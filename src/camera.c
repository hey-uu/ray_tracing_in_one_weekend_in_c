#include "camera.h"
#include "vector3.h"
#include "ray.h"
#include "s_image.h"
#include "utils.h"

t_ray	get_cam_ray(t_camera *cam, double u, double v)
{
	const t_vector	random_dist = v_mul(random_in_unit_disk(), cam->lens_radius);
	const t_vector	offset = v_add(v_mul(cam->base.side, random_dist.x), \
									v_mul(cam->base.up, random_dist.y));
	const t_vector	dir = v_subtract(v_add(v_add(cam->focus.lower_left_corner, \
							v_mul(cam->focus.horizontal, u)), \
							v_mul(cam->focus.vertical, v)), \
							v_add(cam->origin, offset));

	return (get_ray(v_add(cam->origin, offset), dir));
}

void	init_focus_plane(t_camera *cam, double focus_distance)
{
	cam->focus.dist = focus_distance;
	cam->focus.horizontal = v_mul(\
						cam->base.side, cam->focus.dist * cam->viewport.width);
	cam->focus.vertical = v_mul(\
						cam->base.up, cam->focus.dist * cam->viewport.height);
	cam->focus.lower_left_corner = v_subtract(v_subtract(v_subtract(\
									cam->origin, \
									v_div(cam->focus.horizontal, 2)), \
									v_div(cam->focus.vertical, 2)), \
									v_mul(cam->base.dir, cam->focus.dist));	
}

void	init_camera(\
		t_camera *cam, t_point look_from, t_point look_at, double aperture)
{
	cam->origin = look_from;
	cam->look_at = look_at;
	cam->base.dir = get_unit_vector(v_subtract(look_from, look_at));
	cam->base.side = get_unit_vector(v_cross_product(UP_VECTOR, cam->base.dir));
	cam->base.up = v_cross_product(cam->base.dir, cam->base.side);
	cam->lens_radius = aperture / 2;
}

void	init_viewport(\
		t_viewport *viewport, t_image *image, double horizontal_field_of_view)
{
	viewport->aspect_ratio = image->aspect_ratio;
	viewport->horizontal_field_of_view = horizontal_field_of_view;
	viewport->width = 2 * tan(deg_to_rad(horizontal_field_of_view) / 2);
	viewport->height = viewport->width / viewport->aspect_ratio;
}
