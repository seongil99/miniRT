/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:06:37 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/08 14:28:29 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_calloc2(size_t cnt, size_t size)
{
	void	*ret;

	ret = ft_calloc(cnt, size);
	if (!ret)
	{
		perror("miniRT: ft_calloc2");
		exit(1);
	}
	return (ret);
}
