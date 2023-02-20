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

void	add_ground_object(t_object_array *world)
{
	t_material	ground_material;
	t_sphere	ground;

	ground_material = get_material(LAMBERTIAN, &GROUND_MATERIAL);
	ground = get_sphere(get_point(0, -1000, 0), 1000, ground_material);
	add_object(world, &ground, OBJ_SPHERE);
}

void	add_objects(t_object_array *world)
{
	int			i;
	int			j;
	double		choose_material;
	t_point		center;
	t_material	sphere_material;
	t_color		albedo;
	double		fuzz;
	t_sphere	sphere;

	add_ground_object(world);
	i = -11;
	while (i < 11)
	{
		j = -11;
		while (j < 11)
		{
			choose_material = random_double();
			center = get_point(i + 0.9 * random_double(), 0.2, j + 0.9 * random_double());
			if (v_len(v_subtract(center, get_point(4, 0.2, 0))) > 0.9)
			{
				if (choose_material < 0.8)
				{
					albedo = v_componentwise_product(\
							random_vector(0, 1), random_vector(0, 1));
					sphere_material = get_material(LAMBERTIAN, &(t_lambertian){albedo});
					sphere = get_sphere(center, 0.2, sphere_material);
					add_object(world, &sphere, OBJ_SPHERE);
				}
				else if (choose_material < 0.95)
				{
					albedo = random_vector(0.5, 1);
					fuzz = random_double_interval(0, 0.5);
					sphere_material = get_material(METAL, &(t_metal){albedo, fuzz});
					sphere = get_sphere(center, 0.2, sphere_material);
					add_object(world, &sphere, OBJ_SPHERE);
				}
				else
				{
					sphere_material = get_material(DIELECTRIC, &(t_dielectric){1.5});
					sphere = get_sphere(center, 0.2, sphere_material);
					add_object(world, &sphere, OBJ_SPHERE);
				}
			}
			j++;
		}
		i++;
	}
	sphere_material = get_material(DIELECTRIC, &(t_dielectric){1.5});
	sphere = get_sphere(get_point(0, 1, 0), 1.0, sphere_material);
    add_object(world, &sphere, OBJ_SPHERE);

    sphere_material = get_material(\
					LAMBERTIAN, &(t_lambertian){get_color(0.4, 0.2, 0.1)});
	sphere = get_sphere(get_point(-4, 1, 0), 1.0, sphere_material);
    add_object(world, &sphere, OBJ_SPHERE);

    sphere_material = get_material\
					(METAL, &(t_metal){get_color(0.7, 0.6, 0.5), 0});
	sphere = get_sphere(get_point(4, 1, 0), 1.0, sphere_material);
    add_object(world, &sphere, OBJ_SPHERE);
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

	init_image(&info.image, IMG_WIDTH, IMG_ASPECT_RATIO);
	init_viewport(&info.camera.viewport, &info.image, FIELD_OF_VIEW);
	init_camera(&info.camera, LOOK_FROM, LOOK_AT, APERTURE);
	init_focus_plane(&info.camera, FOCAL_DISTANCE);
	init_object_array(&info.world, 10);
	add_objects(&info.world);
	do_rendering(&info);
	flush_object_array(&info.world);
}
