/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:23:57 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 18:21:53 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_ray		t_ray;
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_sphere		t_sphere;
typedef struct s_cylinder	t_cylinder;
typedef struct s_plain		t_plain;
typedef struct s_hit_record	t_hit_record;
typedef struct s_object		t_object;
typedef struct s_light		t_light;
typedef struct s_hit_record	t_hit_record;
typedef struct s_object		t_object;
typedef struct s_scene		t_scene;

typedef int					t_bool;
typedef int					t_object_type;

# define FALSE 0
# define TRUE 1
# define SP 0
# define PL 1
# define CY 2
# define LIGHT_POINT 3
# define EPSILON 1e-6 // 0.000001
# define LUMEN 3  // 이 값을 조절하여 장면의 밝기를 조절할 수 있다.

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_img	*image;
}	t_vars;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

/**
 * 카메라 구조체
 * org - 카메라 원점
 * dir - 카메라 방향벡터
 * left_bottom - 왼쪽 아래 점
 * fov - 화각
 * focal_len - focal length
 * viewport_h - 뷰포트 세로길이
 * viewport_w - 뷰포트 가로길이
 * horizontal - 수평길이 벡터
 * vertical - 가로길이 벡터
*/
struct s_camera
{
	t_point3	orig;
	t_vec3		dir;
	t_point3	left_bottom;
	double		fov;
	double		focal_len;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
};

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_plain
{
	t_point3	point;
	t_vec3		normal;
	double		const_term;
};

struct s_cylinder
{
	t_point3	center_top;
	t_point3	center_down;
	t_vec3		axis_top;
	t_vec3		axis_down;
	double		height;
	double		r;
	double		r2;
};

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	int			type;
	t_color3	albedo;
};

struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
};

struct	s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

#endif
