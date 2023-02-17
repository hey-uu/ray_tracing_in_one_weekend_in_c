
#include "sphere.h"
#include "vector3.h"
#include "discriminant.h"
#include "ray.h"
#include "color.h"
#include <stdio.h>

t_sphere	get_sphere(t_point center, double radius, t_material material)
{
	t_sphere	s;

	s.center = center;
	s.radius = radius;
	s.material = material;
	return (s);
}

t_bool	sphere_hit(\
		t_sphere *s, t_ray *r, t_hit_record *record, double t_min, double t_max)
{
	const t_vector	oc = v_subtract(r->origin, s->center);
	const t_discr	d = get_discriminant(v_len_sqr(r->dir), \
										v_dot_product(oc, r->dir), \
										v_len_sqr(oc) - s->radius * s->radius);
	double			root;

	if (d.discriminant < 0)
		return (FALSE);
	root = d.root1;
	if (root < t_min || root > t_max)
	{
		root = d.root2;
		if (root < t_min || root > t_max)
			return (FALSE);
	}
	record->t = root;
	record->p = ray_at(r, root);
	record->material = &s->material;
	sphere_set_face_normal(\
			record, r, v_div(v_subtract(record->p, s->center), s->radius));
	return (TRUE);
}

void	sphere_set_face_normal(\
		t_hit_record *record, t_ray *r, t_vector outward_normal)
{
	record->front_face = (v_dot_product(r->dir, outward_normal) < 0);
	if (record->front_face > 0)
	{
		record->normal = outward_normal;
	}
	else
		record->normal = v_mul(outward_normal, -1);
}