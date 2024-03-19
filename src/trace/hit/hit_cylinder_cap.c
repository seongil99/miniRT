/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_cap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:59:31 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/19 20:32:28 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

double	cylinder_cap_root(double root1, double root2)
{
	if (root1 < root2)
	{
		if (root1 < rec->tmin || rec->tmax < root1 || \
		vlength2(vminus(cy->center_down, ray_at(ray, root1))) > cy->radius2)
		{
			if (root2 < rec->tmin || rec->tmax < root2 || \
			vlength2(vminus(cy->center_top, ray_at(ray, root2))) > cy->radius2)
				return (FALSE);
			return (root2);
		}
		return (root1);
	}
	else
	{
		if (root2 < rec->tmin || rec->tmax < root2 || \
		vlength2(vminus(cy->center_top, ray_at(ray, root2))) > cy->radius2)
		{
			if (root1 < rec->tmin || rec->tmax < root1 || \
			vlength2(vminus(cy->center_down, ray_at(ray, root1))) > cy->radius2)
				return (FALSE);
			return (root1);
		}
		return (root2);
	}
}

t_bool	hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double		denom;
	double		root1;
	double		root2;
	double		root;
	
	denom = vdot(ray->dir, cy->axis_down);
	if (!denom)
		return (FALSE);
	root1 = vdot(vminus(cy->center_down, ray->orig), cy->axis_down) / denom;
	root2 = -vdot(vminus(cy->center_top, ray->orig), cy->axis_top) / denom;
	root = cylinder_cap_root(root1, root2);
	rec->t = root;
	rec->tmax = rec->t;
	rec->p = ray_at(ray, rec->t);
	if (root == root1)
		rec->normal = cy->axis_down;
	else
		rec->normal = cy->axis_top;
	rec->type = PL;
	set_face_normal(ray, rec);
	return (TRUE);
}
