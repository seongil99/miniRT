/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:06:37 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/22 12:33:27 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	*ft_calloc2(size_t cnt, size_t size)
{
	void	*ret;

	ret = ft_calloc(cnt, size);
	if (!ret)
	{
		exit_err("Memory Error\n");
	}
	return (ret);
}
