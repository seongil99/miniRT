/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:18:01 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 18:28:12 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "scene.h"

void	parse_cylinder(t_scene *scene, char **split, t_parse_data *data)
{
	t_point3	crd;
	double		diameter;
	double		height;
	t_color3	color;
	t_vec3		nvec;

	++data->num_cylinder;
	if (split_size(split) != 6)
		exit_err(ERR_WRONG_VALUE);
	crd = parse_crd(split[1]);
	nvec = parse_nvec(split[2]);
	diameter = ft_atof(split[3]);
	height = ft_atof(split[4]);
	color = parse_color(split[5]);
	if (diameter <= 0.0 || height <= 0.0)
		exit_err(ERR_WRONG_VALUE);
	oadd(&scene->world,
		object(CY, cylinder(crd, nvec, height, diameter), color));
}
