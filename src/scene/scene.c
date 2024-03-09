/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:50:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/09 18:30:11 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

double	get_tan(double degree)
{
	const double	radian = M_PI / 180.0;

	return (tan(degree * radian));
}

double	get_diagnal(double a, double b)
{
	return (sqrt(a * a + b * b));
}

t_camera	camera(t_canvas *canvas, t_point3 orig, t_vec3 dir, double fov)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;

	viewport_height = 2.0;
	cam.orig = orig;
	cam.dir = dir;
	cam.fov = fov;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	focal_len = get_diagnal(cam.viewport_h, cam.viewport_w) / 2 / get_tan(fov / 2);
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	// 왼쪽 아래 코너점 좌표, origin - horizontal / 2 - vertical / 2 - vec3(0,0,focal_length)
	cam.left_bottom = vminus(
			vminus(vminus(cam.orig, vdivide(cam.horizontal, 2)),
				vdivide(cam.vertical, 2)), vec3(0, 0, focal_len));
	return (cam);
}
