#include "s_object_array.h"
#include "ray.h"
#include "color.h"
#include "vector3.h"
#include <stdio.h>

static t_bool	lambertian_scatter(\
				t_hit_record *record, t_color *attenuation, t_ray *scattered)
{
	t_vector	scatter_dir_vector;

	scatter_dir_vector = v_add(record->normal, random_on_unit_sphere());
	if (v_near_zero(scatter_dir_vector) == TRUE)
		scatter_dir_vector = record->normal;
	*scattered = get_ray(record->p, scatter_dir_vector);
	*attenuation = record->material->constants.lambertian.albedo;
	return (TRUE);
}

static t_bool	metal_scatter(\
				t_ray *ray, t_hit_record *record, \
				t_color *attenuation, t_ray *scattered)
{
	const t_vector	reflected = get_reflect_vector(ray->dir, record->normal);

	*scattered = get_ray(record->p, \
						v_add(reflected, \
						v_mul(random_in_unit_sphere(), \
						record->material->constants.metal.fuzz)));
	*attenuation = record->material->constants.metal.albedo;
	return (v_dot_product(scattered->dir, record->normal) > 0);
}

static t_bool	dielectric_scatter(\
				t_ray *ray, t_hit_record *record, \
				t_color *attenuation, t_ray *scattered)
{
	const t_dielectric	dielectric = record->material->constants.dielectric;
	const t_vector		unit_dir = get_unit_vector(ray->dir);
	double				refract_ratio;
	t_vector			refracted;

	*attenuation = get_color(1, 1, 1);
	if (record->front_face == TRUE)
		refract_ratio = 1 / dielectric.refractive_idx;
	else
		refract_ratio = dielectric.refractive_idx;
	refracted = get_refract_vector(unit_dir, record->normal, refract_ratio);
	*scattered = get_ray(record->p, refracted);
	return (TRUE);
}

t_bool	scatter(\
		t_ray *ray, t_hit_record *record, \
		t_color *attenuation, t_ray *scattered)
{
	if (record->material->type == LAMBERTIAN)
	{
		return (lambertian_scatter(record, attenuation, scattered));
	}
	else if (record->material->type == METAL)
	{
		return (metal_scatter(ray, record, attenuation, scattered));
	}
	else if (record->material->type == DIELECTRIC)
	{
		return (dielectric_scatter(ray, record, attenuation, scattered));
	}
	return (FALSE);
}
