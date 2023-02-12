
#include <stdio.h>
#include "color.h"
#include "utils.h"

t_color	color3(double r, double g, double b)
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

	pixel_color = v3_mul(pixel_color, scale);
	printf("%d %d %d\n", (int)(256 * clamp(pixel_color.x, 0.0, 0.999)), \
						(int)(256 * clamp(pixel_color.y, 0.0, 0.999)), \
						(int)(256 * clamp(pixel_color.z, 0.0, 0.999)));
}
