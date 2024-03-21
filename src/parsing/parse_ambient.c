/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:13:21 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 12:35:33 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

void	parse_ambient(t_scene *scene, char **split, t_parse_data *data)
{
	double		ka;
	t_color3	color;

	++data->num_ambient;
	if (data->num_ambient > 1)
		exit_err(ERR_TOO_MANY_AMBIENT);
	if (split_size(split) != 3)
		exit_err(ERR_WRONG_VALUE);
	ka = ft_atof(split[1]);
	if (ka < 0.0 || ka > 1.0)
		exit_err(ERR_OUT_OF_RANGE);
	color = parse_color(split[2]);
	scene->ambient = vmult(color, ka);
}
