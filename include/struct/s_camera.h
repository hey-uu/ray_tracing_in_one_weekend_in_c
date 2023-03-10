#ifndef S_CAMERA_H
# define S_CAMERA_H

# include "s_ray.h"
# include "s_vector.h"

typedef struct s_viewport
{
	double		aspect_ratio;
	double		height;
	double		width;
	double		horizontal_field_of_view;
}	t_viewport;

typedef struct s_cam_base
{
	t_vector	dir;
	t_vector	side;
	t_vector	up;
}	t_cam_base;

typedef struct s_focus_plane
{
	double		dist;
	t_vector	horizontal;
	t_vector	vertical;
	t_point		lower_left_corner;
}	t_focus_plane;
typedef struct s_camera
{
	t_viewport		viewport;
	double			lens_radius;
	t_point			origin;
	t_point			look_at;
	t_cam_base		base;
	t_focus_plane	focus;
}	t_camera;

#endif