#ifndef CAMERA_H
# define CAMERA_H

# include "s_camera.h"
# include "s_image.h"

t_ray	get_cam_ray(t_camera *cam, double u, double v);
void	init_viewport(\
		t_viewport *viewport, t_image *image, double horizontal_field_of_view);
void	init_camera(\
		t_camera *cam, t_point look_from, t_point look_at, double aperture);
void	init_focus_plane(\
		t_focus_plane *focus, t_cam_base *base, \
		t_viewport *viewport, t_point *origin);
#endif