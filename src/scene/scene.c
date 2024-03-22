/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:50:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/11 16:06:19 by seonyoon         ###   ########.fr       */
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

	cam.orig = orig;
	cam.dir = dir;
	cam.fov = fov;
	cam.viewport_h = 2.0;
	cam.viewport_w = 2.0 * canvas->aspect_ratio;
	focal_len = get_diagnal(cam.viewport_h, cam.viewport_w)
		/ 2 / get_tan(fov / 2);
	cam.focal_len = focal_len;
	if (vlength(vcross(vec3(0, 1, 0), cam.dir)))
		cam.horizontal = vmult(vunit(vcross(cam.dir,
						vec3(0, 1, 0))), cam.viewport_w);
	else
		cam.horizontal = vmult(vunit(vcross(cam.dir,
						vec3(0, 0, -1))), cam.viewport_w);
	cam.vertical = vmult(vunit(
				vcross(cam.horizontal, cam.dir)), cam.viewport_h);
	cam.left_bottom = vminus(
			vminus(vplus(cam.orig, vmult(cam.dir, cam.focal_len)),
				vdivide(cam.horizontal, 2)), vdivide(cam.vertical, 2));
	return (cam);
}
