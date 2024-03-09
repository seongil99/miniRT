/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:42:21 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/09 17:16:43 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "scene.h"

void	parse_light(t_scene *scene, char **split)
{
	t_point3	crd;
	t_color3	color;
	double		brightness;

	if (split_size(split) != 4)
		exit_err(ERR_WRONG_ARGS);
	crd = parse_crd(split[1]);
	brightness = ft_atof(split[2]);
	if (brightness < 0.0 || brightness > 1.0)
		exit_err(ERR_OUT_OF_RANGE);
	color = parse_color(split[3]);
	scene->light = object(LIGHT_POINT,
			light_point(crd, color, brightness),
			color3(0, 0, 0));
}
