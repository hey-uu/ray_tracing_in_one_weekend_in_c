#include "ray.h"
#include "vector3.h"
#include "color.h"
#include "world.h"
#include "material.h"
#include <stdio.h>

t_ray	get_ray(t_point origin, t_vector dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir;
	return (ray);
}

t_point	ray_at(t_ray *ray, double t)
{
	return ((t_point)v_add(ray->origin, v_mul(ray->dir, t)));
}

t_color	ray_color(t_ray *ray, t_object_array *world, int depth)
{
	t_hit_record	record;
	t_ray			scattered;
	t_color			attenuation;

	if (depth <= 0)
		return (get_color(0, 0, 0));
	if (object_array_hit(world, ray, &record, T_MINIMUM, INFINITY) == TRUE)
	{
		if (scatter(ray, &record, &attenuation, &scattered) == FALSE)
			return (get_color(0, 0, 0));
		return (v_componentwise_product(\
				ray_color(&scattered, world, depth - 1), \
				attenuation));
	}
	return (background_color(ray));
}
