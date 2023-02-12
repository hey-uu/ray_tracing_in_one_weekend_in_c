
#include "ray.h"
#include "vector3.h"
#include "color.h"
#include "world.h"
#include <stdio.h>

t_ray	ray(t_pt3 origin, t_vec3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir;
	return (ray);
}

t_pt3	ray_at(t_ray *ray, double t)
{
	return ((t_pt3)v3_add(ray->origin, v3_mul(ray->dir, t)));
}

t_color	ray_color(t_ray *ray, t_obj_arr *world)
{
	t_hit_record	record;
	t_vec3			unit_dir;
	double			t;

	if (object_array_hit(world, ray, &record, 0, INFINITY) == TRUE)
	{
// dprintf(2, ">> SUCCESS <<\n");
// dprintf(2, "normal vector: %lf %lf %lf\n", \//
// record.normal.x, record.normal.y, record.normal.z);
		return (v3_mul(v3_add(record.normal, color3(1, 1, 1)), 0.5));
	}
	unit_dir = v3_unit(ray->dir);
	t = 0.5 * (unit_dir.y + 1);
	return (v3_add(v3_mul(color3(1.0, 1.0, 1.0), 1 - t),\
	 		v3_mul(color3(0.5, 0.7, 1.0), t)));
}