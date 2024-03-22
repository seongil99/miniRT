/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:41:54 by sihkang           #+#    #+#             */
/*   Updated: 2024/03/21 21:31:49 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_light_info	src;

	src.light_dir = vminus(light->origin, scene->rec.p);
	src.light_len = vlength(src.light_dir);
	src.light_ray = ray(vplus(scene->rec.p, \
					vmult(scene->rec.normal, EPSILON)), src.light_dir);
	if (in_shadow(scene->world, src.light_ray, src.light_len))
		return (color3(0, 0, 0));
	src.light_dir = vunit(src.light_dir);
	src.kd = fmax(vdot(scene->rec.normal, src.light_dir) / 2, 0.0);
	src.diffuse = vmult(light->light_color, src.kd);
	src.view_dir = vunit(vmult(scene->ray.dir, -1));
	src.reflect_dir = reflect(vmult(src.light_dir, -1), scene->rec.normal);
	src.spec = pow(fmax(vdot(src.view_dir, src.reflect_dir), 0.0), KSN);
	src.specular = vmult(vmult(light->light_color, KS), src.spec);
	src.brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus(vplus(scene->ambient, src.diffuse), \
			src.specular), src.brightness));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		light_color = vplus(light_color, \
						point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = vplus(light_color, scene->ambient);
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}
