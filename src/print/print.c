#include "print.h"
#include "structures.h"

// [0,1] 로 되어있는 rgb 값을 각각 [0,255]에 맵핑 해서 출력.
void	write_color(t_color3 pixel_color)
{
	printf("%d %d %d\n",
		(int)(255.999 * pixel_color.x),
		(int)(255.999 * pixel_color.y),
		(int)(255.999 * pixel_color.z)
		);
}

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
