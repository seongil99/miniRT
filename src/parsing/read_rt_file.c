/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:14:29 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/16 18:28:56 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include "scene.h"

static void	check_filename(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot)
		exit_err(ERR_WRONG_FILENANME);
	if (ft_strncmp(dot, FILE_EXTENSION, 4) != 0)
		exit_err(ERR_WRONG_FILENANME);
}

static void	parse_line(t_scene *scene, char *line, t_parse_data *data)
{
	char	**split;

	if (!scene || !line)
		return ;
	split = ft_split2(line, ft_isspace);
	if (!split)
		return ;
	if (ft_strncmp(*split, AMBIENT_STR, 3) == 0)
		parse_ambient(scene, split, data);
	else if (ft_strncmp(*split, CAM_STR, 3) == 0)
		parse_camera(scene, split, data);
	else if (ft_strncmp(*split, LIGHT_STR, 3) == 0)
		parse_light(scene, split, data);
	else if (ft_strncmp(*split, SPHERE_STR, 3) == 0)
		parse_sphere(scene, split, data);
	else if (ft_strncmp(*split, PLAIN_STR, 3) == 0)
		parse_plain(scene, split, data);
	else if (ft_strncmp(*split, CYLINDER_STR, 3) == 0)
		parse_cylinder(scene, split, data);
	else
		exit_err(ERR_IDENTIFIER);
	split_clear(split);
}

static void	parse_objects(t_scene *scene, int fd, t_parse_data *data)
{
	char	*line;

	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		parse_line(scene, line, data);
		free(line);
	}
}

void	read_rt_file(t_scene *scene, char *filename)
{
	int				fd;
	t_parse_data	data;

	check_filename(filename);
	ft_bzero(&data, sizeof(t_parse_data));
	ft_bzero(scene, sizeof(t_scene));
	scene->canvas = canvas(WIN_WIDTH, WIN_HEIGHT);
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit_err(ERR_WRONG_FILENANME);
	parse_objects(scene, fd, &data);
	close(fd);
}
