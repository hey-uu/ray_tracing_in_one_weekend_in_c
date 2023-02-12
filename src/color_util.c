
#include <stdio.h>
#include "color.h"

t_color	color3(double r, double g, double b)
{
	t_color	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

void	write_color(t_color	pixel_color)
{
	t_color	color = v3_mul(pixel_color, 255.999);

	printf("%d %d %d\n", (int)color.x, (int)color.y, (int)color.z);
}
