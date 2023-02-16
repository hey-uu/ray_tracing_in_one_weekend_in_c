#ifndef S_CAMERA_H
# define S_CAMERA_H

# include "s_ray.h"
# include "s_vector.h"

typedef struct s_camera
{
	double		aspect_ratio;
	double		viewport_height;
	double		viewport_width;
	double		focal_length;
	t_point		origin;
	t_vector	horizontal;
	t_vector	vertical;
	t_point		lower_left_corner;
}	t_camera;

#endif