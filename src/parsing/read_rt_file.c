/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:14:29 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/08 14:38:00 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

static void	parse_objects(t_scene *scene, int fd)
{
	char	*line;
	char	**split;

	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		split = ft_split2(line, ft_isspace);
		while (*split)
		{
			printf("%s\n", *split);
			split++;
		}
	}
	(void)scene;
}

t_scene	*read_rt_file(char *filename)
{
	int		fd;
	t_scene	*ret;

	ret = ft_calloc2(1, sizeof(t_scene));
	fd = open(filename, O_RDONLY);
	parse_objects(ret, fd);
	close(fd);
	return (ret);
}
