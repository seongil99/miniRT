/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:24:20 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/02 15:51:21 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec3	*vec3_add(t_vec3 *a, t_vec3 *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}

t_vec3	*vec3_sub(t_vec3 *a, t_vec3 *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	return (a);
}

t_vec3	*vec3_mul(t_vec3 *a, int n)
{
	a->x *= n;
	a->y *= n;
	a->z *= n;
	return (a);
}

double	vec3_dot(t_vec3 *a, t_vec3 *b)
{
	double	ret;

	ret = a->x * b->x
		+ a->y * b->y
		+ a->z * b->z;
	return (ret);
}
