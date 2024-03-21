/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:49:21 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 16:27:08 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	new = (t_object *)ft_calloc2(1, sizeof(t_object));
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	sp = (t_sphere *)ft_calloc2(1, sizeof(t_sphere));
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_plain	*plain(t_point3 point, t_vec3 normal)
{
	t_plain	*pl;

	pl = (t_plain *)ft_calloc2(1, sizeof(t_plain));
	pl->point = point;
	pl->normal = normal;
	pl->const_term = -(point.x * normal.x
			+ point.y * normal.y + point.z * normal.z);
	return (pl);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 axis,
		double height, double radius)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)ft_calloc2(1, sizeof(t_cylinder));
	cy->height = height;
	cy->axis_top = axis;
	cy->axis_down = vmult(axis, -1);
	cy->center_top = vplus(center, vmult(axis, height / 2));
	cy->center_down = vminus(center, vmult(axis, height / 2));
	cy->r = radius / 2;
	cy->r2 = cy->r * cy->r;
	return (cy);
}

t_light	*light_point(t_point3 light_origin,
		t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	light = (t_light *)ft_calloc2(1, sizeof(t_light));
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
