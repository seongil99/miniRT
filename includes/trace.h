/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:24:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/08 15:10:45 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

// trace/ray/
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
void		set_face_normal(t_ray *r, t_hit_record *rec);

#endif
