/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:03:32 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/22 12:31:51 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "structures.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	int		t;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	t = (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (t < 0)
		return ;
	dst = data->addr + t;
	*(unsigned int *)dst = color;
}

void	put_color(t_img *data, int x, int y, t_color3 pixel_color)
{
	int	color;

	color = (int)(255.999 * pixel_color.z);
	color |= (int)(255.999 * pixel_color.y) << 8;
	color |= (int)(255.999 * pixel_color.x) << 16;
	my_mlx_pixel_put(data, x, y, color);
}
