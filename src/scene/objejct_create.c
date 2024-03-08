#include "structures.h"
#include "scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	if (!(new = (t_object *)calloc(1, sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	if(!(sp = (t_sphere *)calloc(1, sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_plain		*plain(t_point3 point, t_vec3 normal)
{
	t_plain	*pl;

	if (!(pl = (t_plain *)calloc(1, sizeof(t_plain))))
		return (NULL);
	pl->point = point;
	pl->normal = normal;
	pl->const_term = -(point.x * normal.x + point.y * normal.y + point.z * normal.z);
	return (pl);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 axis, double height, double radius)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)calloc(1, sizeof(t_cylinder))))
		return (NULL);
	cy->center = center;
	cy->axis = axis;
	cy->height = height;
	cy->radius = radius;
	cy->radius2 = radius * radius;
	return (cy);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light *light;

	if(!(light = (t_light *)calloc(1, sizeof(t_light))))
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
