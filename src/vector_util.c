#include "vector3.h"
#include "utils.h"

t_vector	get_vector(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector	random_vector(double min, double max)
{
	return (get_vector(random_double_interval(min, max), \
				random_double_interval(min, max), \
				random_double_interval(min, max)));
}

// random vector in unit sphere
t_vector	random_vector_in_unit_sphere(void)
{
	t_vector	random_point;

	while (1)
	{
		random_point = random_vector(-1, 1);
		if (v_len_sqr(random_point) >= 1)
			continue ;
		return (random_point);
	}
}

t_vector	random_unit_vector(void)
{
	return (v_unit(random_vector_in_unit_sphere()));
}

t_point	get_point(double x, double y, double z)
{
	return ((t_point)get_vector(x, y, z));
}

t_vector	get_reflect_vector(t_vector v, t_vector n)
{
	return (v_subtract(v, v_mul(n, 2 * v_dot(v, n))));
}