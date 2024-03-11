/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:26:10 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/11 13:26:51 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	minirt(t_vars *var, t_scene *scene, char *filename);

void	check(void)
{
	system("leaks miniRT");
}

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

int	main(int argc, char *argv[])
{
	t_img	img;
	t_vars	vars;
	t_scene	scene;

	// atexit(check);
	if (argc != 2)
		exit_err("Need 1 scene file .rt\n");
	vars.image = &img;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	minirt(&vars, &scene, argv[1]);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	exit(0);
}
