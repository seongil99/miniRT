/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:32:35 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/20 13:42:03 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

double	get_root(double a, double half_b, double c, t_hit_record *rec)
{
	double	sqrtd;
	double	root;
	double	dst;

	dst = half_b * half_b - a * c;
	if (dst < 0)
		return (FALSE);
	sqrtd = sqrt(dst);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	return (root);
}

double	cylinder_dst(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		ret;

	oc = vminus(ray->orig, cy->center_down);
	a = 1 - pow(vdot(ray->dir, cy->axis_top), 2);
	half_b = vdot(vminus(ray->dir, \
			vmult(cy->axis_top, vdot(ray->dir, cy->axis_top))), \
			vminus(oc, vmult(cy->axis_top, vdot(oc, cy->axis_top))));
	c = vlength2(oc) - pow(vdot(cy->axis_top, oc), 2) - cy->r2;
	ret = get_root(a, half_b, c, rec);
	if (ret == 0)
		return (0);
	else
		return (ret);
}

t_bool	hit_cylinder_body(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	double		root;
	double		contact_height;
	t_vec3		pc;
	t_cylinder	*cy;

	cy = cy_obj->element;
	root = cylinder_dst(cy, ray, rec);
	if (root == 0)
		return (FALSE);
	pc = vminus(ray_at(ray, root), cy->center_down);
	contact_height = vdot(pc, cy->axis_top);
	if (contact_height > cy->height || contact_height < 0)
		return (FALSE);
	rec->type = CY;
	rec->t = root;
	rec->tmax = rec->t;
	rec->p = ray_at(ray, root);
	rec->normal = get_unit_vec_cylinder(cy, rec->p, contact_height);
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_bool		result;

	result = 0;
	result += hit_cylinder_body(cy_obj, ray, rec);
	cy = cy_obj->element;
	result += hit_cylinder_cap(cy, ray, rec);
	if (result)
		rec->albedo = cy_obj->albedo;
	return (result);
}
