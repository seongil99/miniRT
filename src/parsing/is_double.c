/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:16:38 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/08 15:48:47 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

int	is_double(const char *s)
{
	int	flag;

	flag = 0;
	if (!s || !*s)
		return (0);
	if (!(ft_isdigit(*s) || *s == '-' || *s == '+'))
		return (0);
	++s;
	while (*s)
	{
		if (!(ft_isdigit(*s) || *s == '.'))
			return (0);
		if (!flag && *s == '.')
			flag = 1;
		else if (flag && *s == '.')
			return (0);
		++s;
	}
	if (!ft_isdigit(*--s))
		return (0);
	return (1);
}
