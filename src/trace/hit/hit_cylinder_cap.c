/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_cap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:59:31 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/20 20:37:18 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

double	cylinder_cap_root(t_cylinder *cy, t_ray *ray, double root[2], \
						t_hit_record *rec)
{
	if (root[0] < root[1])
	{
		if (root[0] < rec->tmin || rec->tmax < root[0] || \
		vlength2(vminus(cy->center_down, ray_at(ray, root[0]))) > cy->r2)
		{
			if (root[1] < rec->tmin || rec->tmax < root[1] || \
			vlength2(vminus(cy->center_top, ray_at(ray, root[1]))) > cy->r2)
				return (FALSE);
			return (root[1]);
		}
		return (root[0]);
	}
	else
	{
		if (root[1] < rec->tmin || rec->tmax < root[1] || \
		vlength2(vminus(cy->center_top, ray_at(ray, root[1]))) > cy->r2)
		{
			if (root[0] < rec->tmin || rec->tmax < root[0] || \
			vlength2(vminus(cy->center_down, ray_at(ray, root[0]))) > cy->r2)
				return (FALSE);
			return (root[0]);
		}
		return (root[1]);
	}
}

t_bool	hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double		denom;
	double		root[2];
	double		display_root;

	denom = vdot(ray->dir, cy->axis_down);
	if (!denom)
		return (FALSE);
	root[0] = vdot(vminus(cy->center_down, ray->orig), cy->axis_down) / denom;
	root[1] = -vdot(vminus(cy->center_top, ray->orig), cy->axis_top) / denom;
	display_root = cylinder_cap_root(cy, ray, root, rec);
	if (display_root == FALSE)
		return (FALSE);
	rec->t = display_root;
	rec->tmax = rec->t;
	rec->p = ray_at(ray, rec->t);
	if (display_root == root[0])
		rec->normal = cy->axis_down;
	else
		rec->normal = cy->axis_top;
	rec->type = PL;
	set_face_normal(ray, rec);
	return (TRUE);
}
