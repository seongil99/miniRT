/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:58:21 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/20 18:52:47 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

t_vec3	get_unit_vec_cylinder(t_cylinder *cy, t_vec3 at_point, \
								double contact_height)
{
	t_point3	hit_center;
	t_vec3		normal;

	hit_center = vplus(cy->center_down, vmult(cy->axis_top, contact_height));
	normal = vminus(at_point, hit_center);
	return (vunit(normal));
}
