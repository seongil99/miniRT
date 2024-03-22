/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:24:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 21:25:21 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

// decide specular lighting effect coefficients
# define KSN 42
# define KS 0.42

// trace/ray/
typedef struct s_light_info
{
	t_color3	diffuse;
	t_vec3		light_dir;
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		light_len;
	t_ray		light_ray;
	double		spec;
	double		kd;
	double		brightness;
}				t_light_info;

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *scene);
t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_bool		in_shadow(t_object *objs, t_ray light_ray, double light_len);

// trace/hit/
t_bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_plain(t_object *pl_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_object *pl_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *r, t_hit_record *rec);
t_vec3		get_unit_vec_cylinder(t_cylinder *cy, t_vec3 at_point, \
								double contact_height);

#endif
