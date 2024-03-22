/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:54:24 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 16:25:36 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "scene.h"

void	parse_sphere(t_scene *scene, char **split, t_parse_data *data)
{
	t_point3	crd;
	double		diameter;
	t_color3	color;

	++data->num_sphere;
	if (split_size(split) != 4)
		exit_err(ERR_WRONG_VALUE);
	crd = parse_crd(split[1]);
	diameter = ft_atof(split[2]);
	color = parse_color(split[3]);
	if (diameter < 0.0)
		exit_err(ERR_WRONG_VALUE);
	oadd(&scene->world, object(SP, sphere(crd, diameter / 2), color));
}
