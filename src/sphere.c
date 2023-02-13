
#include "sphere.h"
#include "vector3.h"
#include "discriminant.h"
#include "ray.h"
#include "color.h"
#include <stdio.h>

t_sphere	sphere(t_pt3 center, double radius)
{
	t_sphere	s;

	s.center = center;
	s.radius = radius;
	return (s);
}

t_bool	sphere_hit(\
		t_sphere *s, t_ray *r, t_hit_record *record, double t_min, double t_max)
{
	const t_vec3	oc = v3_subtract(r->origin, s->center);
	const t_discr	d = get_discriminant(v3_len_sqr(r->dir), \
										v3_dot(oc, r->dir), \
										v3_len_sqr(oc) - s->radius * s->radius);
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
	sphere_set_face_normal(\
			record, r, v3_div(v3_subtract(record->p, s->center), s->radius));
	return (TRUE);
}

t_color	sphere_color(t_sphere *s, t_ray *r)
{
	t_vec3			unit_dir;
	t_hit_record	record;
	double			t;

	if (sphere_hit(s, r, &record, T_MIN, T_INFINITY) == TRUE)
	{
		return (v3_div(v3_add(record.normal, vec3(1, 1, 1)), 2));
	}
	unit_dir = v3_unit(r->dir);
	t = 0.5 * (unit_dir.y + 1);
	return (v3_add(v3_mul(color3(1.0, 1.0, 1.0), 1 - t), \
			v3_mul(color3(0.5, 0.7, 1.0), t)));
}

void	sphere_set_face_normal(\
		t_hit_record *record, t_ray *r, t_vec3 outward_normal)
{
	record->front_face = (v3_dot(r->dir, outward_normal) < 0);
	if (record->front_face > 0)
	{
		record->normal = outward_normal;
	}
	else
		record->normal = v3_mul(outward_normal, -1);
}