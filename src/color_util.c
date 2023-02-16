#include <stdio.h>
#include "color.h"
#include "utils.h"
#include "s_ray.h"

t_color	get_color(double r, double g, double b)
{
	t_color	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

void	write_color(t_color pixel_color, int samples_per_pixel)
{
	const double	scale = 1.0 / samples_per_pixel;

	pixel_color = v_mul(pixel_color, scale);
	pixel_color.x = sqrt(pixel_color.x);
	pixel_color.y = sqrt(pixel_color.y);
	pixel_color.z = sqrt(pixel_color.z);
	printf("%d %d %d\n", (int)(256 * clamp(pixel_color.x, 0.0, 0.999)), \
						(int)(256 * clamp(pixel_color.y, 0.0, 0.999)), \
						(int)(256 * clamp(pixel_color.z, 0.0, 0.999)));
}

t_color	background_color(t_ray *ray)
{
	const t_vector	unit_dir = v_unit(ray->dir);
	const double	t = 0.5 * (unit_dir.y + 1);

	return (v_add(v_mul(get_color(1, 1, 1), 1 - t), \
				v_mul(get_color(0.5, 0.7, 1.0), t)));
}
