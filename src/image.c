#include "s_image.h"

void	init_image(t_image *img, int width, double aspect_ratio)
{
	img->aspect_ratio = aspect_ratio;
	img->width = width;
	img->height = (int)(img->width / img->aspect_ratio);
}
