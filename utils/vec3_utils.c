/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:44:46 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/02 15:50:03 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

double	vec3_len_sq(t_vec3 *a)
{
	double	ret;

	ret = a->x * a->x
		+ a->y * a->y
		+ a->z * a->z;
	return (ret);
}

double	vec3_len(t_vec3 *a)
{
	return (sqrt(vec3_len_sq(a)));
}
