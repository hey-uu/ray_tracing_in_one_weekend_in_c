#ifndef S_CAMERA_H
# define S_CAMERA_H

# include "s_ray.h"
# include "s_vector.h"

typedef struct s_camera
{
	double	aspect_ratio;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_pt3	origin;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_pt3	lower_left_corner;
}	t_camera;

#endif