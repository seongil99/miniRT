/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:26:10 by seonyoon          #+#    #+#             */
/*   Updated: 2024/02/25 12:32:52 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_hook(void)
{
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
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

int	main(int argc, char *argv[])
{
	t_img	img;
	t_vars	vars;

	(void)argc;
	(void)argv;
	vars.image = &img;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	for (int i = 0; i < WIN_WIDTH / 2; i++)
		for (int j = 0; j < WIN_HEIGHT / 2; j++)
			my_mlx_pixel_put(&img, WIN_WIDTH / 4 + i, WIN_HEIGHT / 4 + j, 0x7799FF);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
}
