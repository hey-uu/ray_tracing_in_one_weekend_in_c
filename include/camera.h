#ifndef CAMERA_H
# define CAMERA_H

# include "s_camera.h"

t_ray	get_cam_ray(t_camera *cam, double u, double v);
void	init_camera(t_camera *cam);
void	set_camera_location(t_camera *cam, t_point origin);

#endif