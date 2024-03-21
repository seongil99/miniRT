/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_comma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:25:46 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 12:32:18 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_commma(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (*str == ',')
			++ret;
		str++;
	}
	return (ret);
}
