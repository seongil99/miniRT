/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:18:05 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/09 17:40:23 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "scene.h"

void	parse_plain(t_scene *scene, char **split)
{
	t_point3	crd;
	t_vec3		nvec;
	t_color3	color;

	if (split_size(split) != 4)
		exit_err(ERR_WRONG_ARGS);
	crd = parse_crd(split[1]);
	nvec = parse_nvec(split[2]);
	color = parse_color(split[3]);
	oadd(&scene->world, object(PL, plain(crd, nvec), color));
}
