/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:54:24 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/09 17:40:27 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "scene.h"

void	parse_sphere(t_scene *scene, char **split)
{
	t_point3	crd;
	double		diameter;
	t_color3	color;

	if (split_size(split) != 4)
		exit_err(ERR_WRONG_ARGS);
	crd = parse_crd(split[1]);
	diameter = ft_atof(split[2]);
	color = parse_color(split[3]);
	if (diameter < 0.0)
		exit_err(ERR_WRONG_VALUE);
	oadd(&scene->world, object(SP, sphere(crd, diameter), color));
}
