#include "camera.h"
#include "vector3.h"
#include "ray.h"

t_ray	get_cam_ray(t_camera *cam, double u, double v)
{
	t_vec3	dir;

	dir = v3_subtract(v3_add(v3_add(\
			cam->lower_left_corner, \
			v3_mul(cam->horizontal, u)), \
			v3_mul(cam->vertical, v)), \
			cam->origin);
	return (ray(cam->origin, dir));
}

void	set_camera_location(t_camera *cam, t_pt3 origin)
{
	cam->origin = origin;
	cam->horizontal = v3_add(origin, vec3(cam->viewport_width, 0.0, 0.0));
	cam->vertical = v3_add(origin, vec3(0.0, cam->viewport_height, 0.0));
	cam->lower_left_corner = v3_subtract(v3_subtract(v3_subtract(\
							origin, \
							v3_div(cam->horizontal, 2)), \
							v3_div(cam->vertical, 2)), \
							vec3(0, 0, cam->focal_length));
}

void	init_camera(t_camera *cam)
{
	cam->aspect_ratio = 16.0 / 9.0;
	cam->viewport_height = 2.0;
	cam->viewport_width = cam->aspect_ratio * cam->viewport_height;
	cam->focal_length = 1.0;
	set_camera_location(cam, point3(0.0, 0.0, 0.0));
}
