/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:43:16 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 12:35:38 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "scene.h"

void	parse_camera(t_scene *scene, char **split, t_parse_data *data)
{
	t_point3	org;
	t_vec3		dir;
	int			fov;

	++data->num_camera;
	if (data->num_camera > 1)
		exit_err(ERR_TOO_MANY_CAMERA);
	if (split_size(split) != 4)
		exit_err(ERR_WRONG_VALUE);
	org = parse_crd(split[1]);
	dir = parse_nvec(split[2]);
	fov = ft_atof(split[3]);
	if (fov < 0.0 || fov > 180.0)
		exit_err(ERR_OUT_OF_RANGE);
	scene->camera = camera(&scene->canvas, org, dir, fov);
}
