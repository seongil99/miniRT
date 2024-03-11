#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"
#include "parsing.h"

// t_scene	*scene_init(void)
// {
// 	t_scene		*scene;
// 	t_object	*world;
// 	t_object	*lights;
// 	double		ka; // 8.4 에서 설명

// 	// malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
// 	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
// 		return (NULL);
// 	scene->canvas = canvas(WIN_WIDTH, WIN_HEIGHT);
// 	scene->camera = camera(&scene->canvas, point3(0, 0, 0), vunit(vec3(0, 0, -1)), 114);
// 	// world = object(PL, plain(point3(0, -2, 0), vunit(vec3(0, 1, 0))), color3(0, 0, 1));
// 	// oadd(&world, object(PL, plain(point3(-10, 0, 0), vunit(vec3(1, 3, 0))), color3(1, 0, 0)));
// 	// oadd(&world, object(PL, plain(point3(0, 0, -20), vunit(vec3(0, 0, 1))), color3(0, 1, 0)));
// 	// oadd(&world, object(SP, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0))); // world 에 구1 추가
// 	world = object(SP, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0));
// 	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0))); // world 에 구2 추가
// 	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 998), color3(0.5, 0.5, 0.9))); // world 에 구3 추가
// 	// oadd(&world, object(PL, plain(point3(0, 5, 5), vunit(vec3(0, 1, 0))), color3(0, 0, 1)));
// 	scene->world = world;
// 	lights = object(LIGHT_POINT, light_point(point3(10, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0)); // 더미 albedo
// 	scene->light = lights;
// 	ka = 0.2; // 8.4 에서 설명
// 	scene->ambient = vmult(color3(1, 1, 1), ka); // 8.4 에서 설명
// 	return (scene);
// }

int	minirt(t_vars *var, t_scene *scene, char *filename)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;

	//Scene setting;
	// scene = scene_init();
	read_rt_file(scene, filename);
	// 랜더링
	j = 0;
	while (j <= scene->canvas.height)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			//ray from camera origin to pixel
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			// ray_color함수의 인자도 ray, world를 모두 담고 있는 scene으로 바꿨다.
			// write_color(pixel_color);
			put_color(var->image, i, WIN_HEIGHT - j, pixel_color);
			++i;
		}
		++j;
	}
	return (0);
}
