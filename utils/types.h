/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:01:14 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/02 18:30:20 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_vec3	t_point;
typedef struct s_vec3	t_vec3;

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

typedef enum e_figure_type
{
	PLANE = 1,
	SPHERE,
	CYLINDER
}	t_figure_type;

typedef struct s_object
{
	t_figure_type	type;
	t_point			crd;
	t_vec3			nor_vec;
	double			r;
	double			h;
	int				color;
}	t_object;

typedef struct s_ray
{
	t_point	org;
	t_vec3	dir;
}	t_ray;

#endif
