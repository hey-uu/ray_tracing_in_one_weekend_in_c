#include "camera.h"
#include "vector3.h"
#include "ray.h"
#include "s_image.h"
#include "utils.h"

t_ray	get_cam_ray(t_camera *cam, double u, double v)
{
	t_vector	dir;

	dir = v_subtract(v_add(v_add(\
			cam->viewport.lower_left_corner, \
			v_mul(cam->viewport.horizontal, u)), \
			v_mul(cam->viewport.vertical, v)), \
			cam->origin);
	return (get_ray(cam->origin, dir));
}

static void	init_viewport_vectors(t_camera *cam)
{
	cam->viewport.horizontal = v_mul(cam->base.side, cam->viewport.width);
	cam->viewport.vertical = v_mul(cam->base.up, cam->viewport.height);
	cam->viewport.lower_left_corner = v_subtract(v_subtract(v_subtract(\
							cam->origin, \
							v_div(cam->viewport.horizontal, 2)), \
							v_div(cam->viewport.vertical, 2)), \
							cam->base.dir);
}

void	init_camera(t_camera *cam, t_point look_from, t_point look_at)
{
	cam->origin = look_from;
	cam->look_at = look_at;
	cam->base.dir = get_unit_vector(v_subtract(look_from, look_at));
	cam->base.side = get_unit_vector(v_cross_product(UP_VECTOR, cam->base.dir));
	cam->base.up = v_cross_product(cam->base.dir, cam->base.side);
	init_viewport_vectors(cam);
}

void	init_viewport(\
		t_viewport *viewport, t_image *image, double horizontal_field_of_view)
{
	viewport->aspect_ratio = image->aspect_ratio;
	viewport->horizontal_field_of_view = horizontal_field_of_view;
	viewport->width = 2 * tan(deg_to_rad(horizontal_field_of_view) / 2);
	viewport->height = viewport->width / viewport->aspect_ratio;
}
