/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:29:51 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 12:35:44 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

t_color3	parse_color(char *str)
{
	char		**split;
	t_color3	ret;

	if (count_commma(str) != 2)
		exit_err(ERR_WRONG_VALUE);
	split = ft_split2(str, is_comma);
	if (split_size(split) != 3)
		exit_err(ERR_WRONG_VALUE);
	ret.x = ft_atof(split[0]);
	ret.y = ft_atof(split[1]);
	ret.z = ft_atof(split[2]);
	split_clear(split);
	if (ret.x < 0.0 || ret.x > 255.0
		|| ret.y < 0.0 || ret.y > 255.0
		|| ret.y < 0.0 || ret.y > 255.0)
		exit_err(ERR_OUT_OF_RANGE);
	return (vmult(ret, 1.0 / 255.0));
}
