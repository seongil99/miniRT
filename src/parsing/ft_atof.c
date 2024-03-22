/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:51:08 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 18:28:00 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

double	ft_atof(const char *s)
{
	double	ret;
	double	t;
	char	**split;

	if (!s || !*s)
		return (0);
	if (!is_double(s))
		exit_err(ERR_WRONG_VALUE);
	split = ft_split2(s, is_dot);
	ret = ft_atoi2(split[0]);
	t = ft_atoi2(split[1]);
	while (t >= 1.0)
	{
		t /= 10.0;
	}
	if (ret < 0)
		t *= -1;
	split_clear(split);
	return (ret + t);
}
