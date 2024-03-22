/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nvec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:47:26 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 12:30:17 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

t_vec3	parse_nvec(char *str)
{
	char	**split;
	t_vec3	ret;

	if (count_commma(str) != 2)
		exit_err(ERR_WRONG_VALUE);
	split = ft_split2(str, is_comma);
	if (split_size(split) != 3)
		exit_err(ERR_WRONG_VALUE);
	ret.x = ft_atof(split[0]);
	ret.y = ft_atof(split[1]);
	ret.z = ft_atof(split[2]);
	split_clear(split);
	if (ret.x < -1.0 || ret.x > 1.0
		|| ret.y < -1.0 || ret.y > 1.0
		|| ret.y < -1.0 || ret.y > 1.0)
		exit_err(ERR_OUT_OF_RANGE);
	return (vunit(ret));
}
