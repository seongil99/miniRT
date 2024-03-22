/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:42:12 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/20 13:42:55 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_plain(t_object *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_plain		*pl;
	double		root;
	double		numer;
	double		denom;

	pl = pl_obj->element;
	denom = vdot(ray->dir, pl->normal);
	if (!denom)
		return (FALSE);
	numer = vdot(vminus(pl->point, ray->orig), pl->normal);
	root = numer / denom;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->type = PL;
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = pl->normal;
	set_face_normal(ray, rec);
	rec->albedo = pl_obj->albedo;
	return (TRUE);
}
