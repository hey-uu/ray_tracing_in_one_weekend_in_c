#include "camera.h"
#include "vector3.h"
#include "ray.h"

t_ray	get_cam_ray(t_camera *cam, double u, double v)
{
	t_vector	dir;

	dir = v_subtract(v_add(v_add(\
			cam->lower_left_corner, \
			v_mul(cam->horizontal, u)), \
			v_mul(cam->vertical, v)), \
			cam->origin);
	return (get_ray(cam->origin, dir));
}

void	set_camera_location(t_camera *cam, t_point origin)
{
	cam->origin = origin;
	cam->horizontal = v_add(origin, get_vector(cam->viewport_width, 0.0, 0.0));
	cam->vertical = v_add(origin, get_vector(0.0, cam->viewport_height, 0.0));
	cam->lower_left_corner = v_subtract(v_subtract(v_subtract(\
							origin, \
							v_div(cam->horizontal, 2)), \
							v_div(cam->vertical, 2)), \
							get_vector(0, 0, cam->focal_length));
}

void	init_camera(t_camera *cam)
{
	cam->aspect_ratio = 16.0 / 9.0;
	cam->viewport_height = 2.0;
	cam->viewport_width = cam->aspect_ratio * cam->viewport_height;
	cam->focal_length = 1.0;
	set_camera_location(cam, get_point(0.0, 0.0, 0.0));
}
