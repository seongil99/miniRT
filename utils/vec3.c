/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:58:33 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/02 14:19:04 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec3	*vec3_new(double x, double y, double z)
{
	t_vec3	*ret;

	ret = ft_calloc2(1, sizeof(t_vec3));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

void	vec3_del(t_vec3 *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
	free(vec);
}
