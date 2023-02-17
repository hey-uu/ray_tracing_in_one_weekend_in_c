#include "vector3.h"

t_vector	get_vector(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point	get_point(double x, double y, double z)
{
	return ((t_point)get_vector(x, y, z));
}

t_vector	get_reflect_vector(t_vector v, t_vector n)
{
	return (v_subtract(v, v_mul(n, 2 * v_dot_product(v, n))));
}

t_vector	get_unit_vector(t_vector v)
{
	return (v_div(v, v_len(v)));
}
