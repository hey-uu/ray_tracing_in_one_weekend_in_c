#include "s_info.h"
#include "image.h"
#include "camera.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "world.h"
#include "utils.h"
#include "material.h"
#include <stdio.h>

void	init_settings(t_info *info)
{
	init_image(&info->image);
	init_camera(&info->camera);
	init_object_array(&info->world, 10);
}

void	add_objects(t_object_array *world)
{
	t_sphere	s;
	t_material	m[4];

	m[0] = get_material(LAMBERTIAN, &(t_lambertian){get_color(0.8, 0.8, 0)});
	m[1] = get_material(LAMBERTIAN, &(t_lambertian){get_color(0.1, 0.2, 0.5)});
	m[2] = get_material(DIELECTRIC, &(t_dielectric){1.5});
	m[3] = get_material(METAL, &(t_metal){get_color(0.8, 0.6, 0.2), 0.0});
	s = get_sphere(get_point(0, -100.5, -1), 100, m[0]);
	object_add(world, &s, OBJ_SPHERE);
	s = get_sphere(get_point(0, 0, -1), 0.5, m[1]);
	object_add(world, &s, OBJ_SPHERE);
	s = get_sphere(get_point(-1, 0, -1), 0.5, m[2]);
	object_add(world, &s, OBJ_SPHERE);
	s = get_sphere(get_point(1, 0, -1), 0.5, m[3]);
	object_add(world, &s, OBJ_SPHERE);
}

t_color	get_pixel_color(t_info *info, int i, int j)
{
	double	u;
	double	v;
	t_ray	ray;
	t_color	pixel_color;
	int		k;

	k = 0;
	pixel_color = get_color(0, 0, 0);
	while (k < SAMPLES_PER_PIXEL)
	{
		u = (double)(i + random_double()) / (info->image.width - 1);
		v = (double)(j + random_double()) / (info->image.height - 1);
		ray = get_cam_ray(&info->camera, u, v);
		pixel_color = v_add(pixel_color, \
					ray_color(&ray, &info->world, MAX_DEPTH));
		k++;
	}
	return (pixel_color);
}

void	do_rendering(t_info *info)
{
	int		i;
	int		j;

	printf("P3\n");
	printf("%d %d\n", info->image.width, info->image.height);
	printf("255\n");
	j = info->image.height - 1;
	while (j >= 0)
	{
		dprintf(2, "Scanlines remaining: %d\n", j);
		i = 0;
		while (i < info->image.width)
		{
			write_color(get_pixel_color(info, i, j), SAMPLES_PER_PIXEL);
			i++;
		}
		j--;
	}
	dprintf(2, ">> Done! <<\n");
}

int	main(void)
{
	t_info	info;

	init_settings(&info);
	add_objects(&info.world);
	do_rendering(&info);
}
