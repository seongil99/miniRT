/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:54:22 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 12:42:47 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

int	ft_atoi2(const char *str)
{
	long long	ret;
	long long	sign;

	ret = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str)
	{
		ret = ret * 10 + (*str - '0');
		if (ret > 1000000LL)
			exit_err(ERR_NUM_TOO_LONG);
		str++;
	}
	return ((int)(sign * ret));
}
