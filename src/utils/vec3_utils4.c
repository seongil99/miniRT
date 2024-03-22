/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:10:56 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/11 16:11:12 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// 단위 벡터
t_vec3	vunit(t_vec3 vec)
{
	double	len;

	len = vlength(vec);
	if (len == 0)
	{
		exit_err("Divider is 0\n");
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}

// 두 벡터의 원소를 비교하여 작은 값들만 반환
t_vec3	vmin(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}
