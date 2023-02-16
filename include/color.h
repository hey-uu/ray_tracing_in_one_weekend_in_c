#ifndef COLOR_H
# define COLOR_H

/** STANDARD HEADER FILE **/
# include "vector3.h"
# include "s_ray.h"

/** FUNCTION **/
t_color	get_color(double r, double g, double b);
void	write_color(t_color pixel_color, int samples_per_pixel);
t_color	background_color(t_ray *ray);

#endif