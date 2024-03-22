/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:32 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/09 12:37:18 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>

void	split_clear(char **sp)
{
	char	**l;

	l = sp;
	if (!l)
		return ;
	while (*l)
	{
		free(*l);
		++l;
	}
	free(sp);
}

int	split_size(char **split)
{
	int	ret;

	if (!split)
		return (0);
	ret = 0;
	while (*split)
	{
		++ret;
		++split;
	}
	return (ret);
}
