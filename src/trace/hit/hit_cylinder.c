/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:32:35 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/14 19:01:49 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_vec3      get_unit_vec_cylinder(t_cylinder *cy, t_vec3 at_point, double contact_height)
{
	t_point3	hit_center;
    t_vec3		normal;

    hit_center = vplus(cy->center, vmult(cy->axis, contact_height));
    normal = vminus(at_point, hit_center);
    return (vunit(normal));
}

t_bool	hit_cylinder_cap(t_plain *cy_cap, t_ray *ray, t_hit_record *rec, double r)
{
	double		root;
	double		numer;
	double		denom;
	t_vec3		contact_point;
	
	denom = vdot(ray->dir, cy_cap->normal);
	if (!denom)
		return (FALSE);
	numer = vdot(vminus(cy_cap->point, ray->orig), cy_cap->normal);
	root = numer / denom;
    if (root < rec->tmin || rec->tmax < root)
        return (FALSE);
	if (root > rec->t)
		return (FALSE);
	contact_point = vplus(ray->orig, vmult(ray->dir, root));
	if (vlength(vminus(cy_cap->point, contact_point)) > r)
		return (FALSE);
	rec->type = CY;
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = cy_cap->normal;
	return (TRUE);
}

t_bool	hit_cylinder_body(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	double		root;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	t_vec3		contact_point;
	double		contact_height;
	t_cylinder	*cy;

	cy = cy_obj->element;
	oc = vminus(ray->orig, cy->center);
	a = vdot(vcross(ray->dir, cy->axis), vcross(ray->dir, cy->axis));
	half_b = vdot(vcross(ray->dir, cy->axis), vcross(vminus(ray->orig, cy->center), cy->axis));
	c = vdot(vcross(vminus(ray->orig, cy->center), cy->axis), vcross(vminus(ray->orig, cy->center), cy->axis)) - cy->radius2;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	contact_point = vminus(vplus(ray->orig, vmult(ray->dir, root)), cy->center);
	if (vdot(vminus(contact_point, cy->center), cy->axis) < 0)
		return (FALSE);
	contact_height = fabs(sqrt(vlength2(contact_point) - cy->radius2));
	if (contact_height > cy->height)
		return (FALSE);
	rec->type = CY;
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = get_unit_vec_cylinder(cy, rec->p, contact_height);
	return (TRUE);
}

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_plain		*cy_cap;
	t_cylinder	*cy;
	t_bool		result;

	result = 0;
	rec->t = 0;
	cy = cy_obj->element;
	cy_cap = cy_obj->element;
	result = hit_cylinder_body(cy_obj, ray, rec);
	// cy_cap->normal = cy->axis;
	// cy_cap->point = vplus(cy->center, vmult(cy_cap->normal, cy->height / 2));
	// result += hit_cylinder_cap(cy_cap, ray, rec, cy->radius);
	// cy_cap->normal = vunit(vmult(cy_cap->normal, -1));
	// cy_cap->point = vplus(cy->center, vmult(cy_cap->normal, cy->height / 2));
	// result += hit_cylinder_cap(cy_cap, ray, rec, cy->radius);
	set_face_normal(ray, rec);
	if (result)
		rec->albedo = cy_obj->albedo;
	return (result);
}
