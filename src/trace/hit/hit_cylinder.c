/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:32:35 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/19 18:24:04 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_vec3      get_unit_vec_cylinder(t_cylinder *cy, t_vec3 at_point, double contact_height)
{
	t_point3	hit_center;
    t_vec3		normal;

    hit_center = vplus(cy->center_down, vmult(cy->axis_top, contact_height));
    normal = vminus(at_point, hit_center);
    return (vunit(normal));
}

// t_plain	*get_root_plain(t_cylinder *cy, t_plain *cy_cap1, t_plain *cy_cap2, t_ray *ray, t_hit_record *rec)
// {
// 	if (cy_cap1->const_term < cy_cap2->const_term)
// 	{
// 		if (cy_cap1->const_term < rec->tmin || rec->tmax < cy_cap1->const_term || \
// 		vlength2(vminus(cy_cap1->point, ray_at(ray, cy_cap1->const_term))) > cy->radius2)
// 		{
// 			if (cy_cap2->const_term < rec->tmin || rec->tmax < cy_cap2->const_term || \
// 			vlength2(vminus(cy_cap2->point, ray_at(ray, cy_cap2->const_term))) > cy->radius2)
// 				return (FALSE);
// 			return (cy_cap2);
// 		}
// 		return (cy_cap1);
// 	}
// 	else
// 	{
// 		if (cy_cap2->const_term < rec->tmin || rec->tmax < cy_cap2->const_term || \
// 		vlength2(vminus(cy_cap2->point, ray_at(ray, cy_cap2->const_term))) > cy->radius2)
// 		{
// 			if (cy_cap1->const_term < rec->tmin || rec->tmax < cy_cap1->const_term || \
// 			vlength2(vminus(cy_cap1->point, ray_at(ray, cy_cap1->const_term))) > cy->radius2)
// 				return (FALSE);
// 			return (cy_cap1);
// 		}
// 		return (cy_cap2);
// 	}
// }

t_bool	hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double		denom;
	double		numer1;
	double		numer2;
	double		root;
	
	denom = vdot(ray->dir, cy->axis_down);
	if (!denom)
		return (FALSE);
	numer1 = vdot(vminus(cy->center_down, ray->orig), cy->axis_down) / denom;
	numer2 = -vdot(vminus(cy->center_top, ray->orig), cy->axis_top) / denom;

	if (numer1 < numer2)
	{
		if (numer1 < rec->tmin || rec->tmax < numer1 || \
		vlength2(vminus(cy->center_down, ray_at(ray, numer1))) > cy->radius2)
		{
			if (numer2 < rec->tmin || rec->tmax < numer2 || \
			vlength2(vminus(cy->center_top, ray_at(ray, numer2))) > cy->radius2)
				return (FALSE);
			root = numer2;
		}
		root = numer1;
	}
	else
	{
		if (numer2 < rec->tmin || rec->tmax < numer2 || \
		vlength2(vminus(cy->center_top, ray_at(ray, numer2))) > cy->radius2)
		{
			if (numer1 < rec->tmin || rec->tmax < numer1 || \
			vlength2(vminus(cy->center_down, ray_at(ray, numer1))) > cy->radius2)
				return (FALSE);
			root = numer1;
		}
		root = numer2;
	}
	rec->t = root;
	rec->tmax = rec->t;
	rec->p = ray_at(ray, rec->t);
	if (root == numer1)
		rec->normal = cy->axis_down;
	else
		rec->normal = cy->axis_top;
	rec->type = PL;
	set_face_normal(ray, rec);
	return (TRUE);
}

// t_bool	hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
// {
// 	double		root;
// 	double		numer;
// 	double		denom;

// 	denom = vdot(ray->dir, cy->axis);
// 	if (!denom)
// 		return (FALSE);
// 	numer = vdot(vminus(cy->center, ray->orig), cy->axis);
// 	root = numer / denom;
//     if (root < rec->tmin || rec->tmax < root)
//         return (FALSE);
// 	if (vlength(vminus(cy->center, ray_at(ray, root))) > cy->radius)
// 		return (FALSE);
// 	rec->type = PL;
// 	rec->t = root;
// 	rec->p = ray_at(ray, root);
// 	rec->tmax = rec->t;
// 	rec->normal = cy->axis;
// 	set_face_normal(ray, rec);
// 	return (TRUE);
// }

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
	half_b = vdot(vminus(ray->dir, vmult(cy->axis_top, vdot(ray->dir, cy->axis_top))), vminus(oc, vmult(cy->axis_top, vdot(oc, cy->axis_top))));
	c = vlength2(oc) - pow(vdot(cy->axis_top, oc), 2) - cy->radius2;
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
	// result += hit_cylinder_cap(cy, ray, rec);
	// cy->axis = vmult(cy->axis, -1);
	// cy->center = vplus(cy->center, vmult(cy->axis, cy->height));
	// result += hit_cylinder_cap(cy, ray, rec);
	// result += hit_cylinder_cap(cy_cap2, ray, rec, cy->radius2);
	if (result)
		rec->albedo = cy_obj->albedo;
	return (result);
}
