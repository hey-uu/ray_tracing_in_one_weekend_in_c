#include "ray_tracing.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "world.h"
#include <stdio.h>

int	main()
{
	// image
	const double	aspect_ratio = 16.0 / 9.0;
	const int		image_width = 400;
	const int		image_height = (int)(image_width / aspect_ratio);

	// camera
	const double	viewport_height = 2.0;
	const double	viewport_width = aspect_ratio * viewport_height;
	const double	focal_length = 1.0;
	const t_pt3		origin = point3(0, 0, 0);
	const t_vec3	horizontal = vec3(viewport_width, 0, 0);
	const t_vec3	vertical = vec3(0, viewport_height, 0);
	t_pt3			lower_left_corner;
	
	lower_left_corner = v3_subtract(origin, v3_div(horizontal, 2));
	lower_left_corner = v3_subtract(lower_left_corner, v3_div(vertical, 2));
	lower_left_corner = v3_subtract(lower_left_corner, vec3(0, 0, focal_length));

	// ray

	t_ray	r;
	t_vec3	dir;

	// world
	t_sphere	s;
	t_obj_arr	world;

	init_object_array(&world, 10);
	s = sphere(point3(0, 0, -1), 0.5);
	object_add(&world, &s, OBJ_SPHERE);
	s = sphere(point3(0, -100.5, -1), 100);
	object_add(&world, &s, OBJ_SPHERE);

	// iterator
	int			i;
	int			j;

	// rgb
	double		u;
	double		v;
	t_color		pixel_color;


	// render
	printf("P3\n");
	printf("%d %d\n", image_width, image_height);
	printf("255\n");
	
	for (j = image_height - 1 ; j >= 0 ; --j)
	{
		dprintf(2, "Scanlines remaining: %d\n", j);
		for (i = 0 ; i < image_width; ++i)
		{
			u = (double)i / (image_width - 1);
			v =	(double)j / (image_height - 1);
			dir = v3_add(lower_left_corner, v3_mul(horizontal, u));
			dir = v3_add(dir, v3_mul(vertical, v));
			r = ray(origin, dir);
			pixel_color = ray_color(&r, &world);
			write_color(pixel_color);
		}
	}
	dprintf(2, ">> Done! <<\n");
}