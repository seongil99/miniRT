/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:14:29 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/09 17:39:45 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include "scene.h"

static void	parse_line(t_scene *scene, char *line)
{
	char	**split;

	if (!scene || !line)
		return ;
	split = ft_split2(line, ft_isspace);
	if (!split || !*split)
		return ;
	if (ft_strncmp(*split, AMBIENT_STR, 3) == 0)
		parse_ambient(scene, split);
	else if (ft_strncmp(*split, CAM_STR, 3) == 0)
		parse_camera(scene, split);
	else if (ft_strncmp(*split, LIGHT_STR, 3) == 0)
		parse_light(scene, split);
	else if (ft_strncmp(*split, SPHERE_STR, 3) == 0)
		parse_sphere(scene, split);
	else if (ft_strncmp(*split, PLAIN_STR, 3) == 0)
		parse_plain(scene, split);
	else if (ft_strncmp(*split, CYLINDER_STR, 3) == 0)
		parse_cylinder(scene, split);
	else
		exit_err(ERR_IDENTIFIER);
	split_clear(split);
}

static void	parse_objects(t_scene *scene, int fd)
{
	char	*line;

	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		if (*line == '\n')
			continue ;
		parse_line(scene, line);
		free(line);
	}
}

t_scene	*read_rt_file(char *filename)
{
	int		fd;
	t_scene	*ret;

	ret = ft_calloc2(1, sizeof(t_scene));
	ret->canvas = canvas(WIN_WIDTH, WIN_HEIGHT);
	fd = open(filename, O_RDONLY);
	parse_objects(ret, fd);
	close(fd);
	return (ret);
}
