/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:55:54 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/21 20:29:41 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			is_hit;
	t_hit_record	tmp;

	tmp = *rec;
	is_hit = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &tmp))
		{
			is_hit = TRUE;
			tmp.tmax = tmp.t;
			*rec = tmp;
		}
		world = world->next;
	}
	return (is_hit);
}

t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	res;

	res = FALSE;
	if (world->type == SP)
		res = hit_sphere(world, ray, rec);
	else if (world->type == PL)
		res = hit_plain(world, ray, rec);
	else if (world->type == CY)
		res = hit_cylinder(world, ray, rec);
	return (res);
}
