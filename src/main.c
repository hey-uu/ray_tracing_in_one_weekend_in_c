#include "image.h"
#include "camera.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "world.h"
#include "utils.h"
#include "material.h"
#include <stdio.h>

void	init_settings(t_image *img, t_camera *cam, t_object_array *world)
{
	init_image(img);
	init_camera(cam);
	init_object_array(world, 10);
}

int	main()
{
	// basic setting
	t_image		image;
	t_camera	camera;
	t_object_array	world;
	// temp objects
	t_sphere			s;
	t_material			m[4];
	// temp ray
	t_ray		r;
	// temp color
	t_color		pixel_color;
	// temp coefficient
	double		u;
	double		v;
	// iterator
	int			i;
	int			j;
	int			k;

	// setting
	init_settings(&image, &camera, &world);

	// add objects
	m[0] = get_material(LAMBERTIAN, &(t_lambertian){get_color(0.8, 0.8, 0)});
	m[1] = get_material(LAMBERTIAN, &(t_lambertian){get_color(0.7, 0.3, 0.3)});
	m[2] = get_material(METAL, &(t_metal){get_color(0.8, 0.8, 0.8), 0});
	m[3] = get_material(METAL, &(t_metal){get_color(0.8, 0.6, 0.2), 0});
	s = get_sphere(get_point(0, -100.5, -1), 100, m[0]);
	object_add(&world, &s, OBJ_SPHERE);
	s = get_sphere(get_point(0, 0, -1), 0.5, m[1]);
	object_add(&world, &s, OBJ_SPHERE);
	s = get_sphere(get_point(-1, 0, -1), 0.5, m[2]);
	object_add(&world, &s, OBJ_SPHERE);
	s = get_sphere(get_point(1, 0, -1), 0.5, m[3]);
	object_add(&world, &s, OBJ_SPHERE);

	// render
	printf("P3\n");
	printf("%d %d\n", image.width, image.height);
	printf("255\n");
	for (j = image.height - 1 ; j >= 0 ; --j)
	{
		dprintf(2, "Scanlines remaining: %d\n", j);
		for (i = 0 ; i < image.width; ++i)
		{
			pixel_color = get_color(0.0, 0.0, 0.0);
			for (k = 0 ; k < SAMPLES_PER_PIXEL; k++)
			{
				u = (double)(i + random_double()) / (image.width - 1);
				v =	(double)(j + random_double()) / (image.height - 1);
				r = get_cam_ray(&camera, u, v);
				t_color tem = ray_color(&r, &world, MAX_DEPTH);
				pixel_color = v_add(\
							pixel_color, tem);
			}
			write_color(pixel_color, SAMPLES_PER_PIXEL);
		}
	}
	dprintf(2, ">> Done! <<\n");
}
