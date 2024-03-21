/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:42:21 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 12:35:56 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "scene.h"

void	parse_light(t_scene *scene, char **split, t_parse_data *data)
{
	t_point3	crd;
	t_color3	color;
	double		brightness;

	++data->num_light;
	if (split_size(split) != 4)
		exit_err(ERR_WRONG_VALUE);
	crd = parse_crd(split[1]);
	brightness = ft_atof(split[2]);
	if (brightness < 0.0 || brightness > 1.0)
		exit_err(ERR_OUT_OF_RANGE);
	color = parse_color(split[3]);
	oadd(&scene->light, object(LIGHT_POINT,
			light_point(crd, color, brightness),
			color3(0, 0, 0)));
}
