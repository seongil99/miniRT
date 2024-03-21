/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:54:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/20 18:52:38 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

double	sphere_root(double a, double half_b, double c, t_hit_record *rec)
{
	double	root;
	double	sqrtd;
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
		return (root);
	}
	return (root);
}

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	double		a;
	double		half_b;
	double		c;
	double		root;

	sp = sp_obj->element;
	a = vlength2(ray->dir);
	half_b = vdot(vminus(ray->orig, sp->center), ray->dir);
	c = vlength2(vminus(ray->orig, sp->center)) - sp->radius2;
	root = sphere_root(a, half_b, c, rec);
	if (root == FALSE)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = sp_obj->albedo;
	return (TRUE);
}
