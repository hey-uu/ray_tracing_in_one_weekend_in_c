#include "s_image.h"

void	init_image(t_image *img)
{
	img->aspect_ratio = 16.0 / 9.0;
	img->width = 400;
	img->height =(int)(img->width / img->aspect_ratio);
}