
#include "vector3.h"

t_vector	v_add(t_vector u, t_vector v)
{
	return (get_vector(u.x + v.x, u.y + v.y, u.z + v.z));
}

t_vector	v_subtract(t_vector u, t_vector v)
{
	return (get_vector(u.x - v.x, u.y - v.y, u.z - v.z));
}

t_vector	v_mul(t_vector v, double t)
{
	return (get_vector(t * v.x, t * v.y, t * v.z));
}

t_vector	v_div(t_vector v, double t)
{
	return (get_vector(v.x / t, v.y / t, v.z / t));
}

double	v_len(t_vector v)
{
	return (sqrt((v.x * v.x + v.y * v.y + v.z * v.z)));
}

double	v_len_sqr(t_vector v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vector	v_unit(t_vector v)
{
	return (v_div(v, v_len(v)));
}

double	v_dot(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vector	v_cross_product(t_vector u, t_vector v)
{
	return (get_vector(u.y * v.z - u.z * v.y, \
				u.z * v.x - u.x * v.z, \
				u.x * v.y - u.y * v.x));
}

t_bool	v_near_zero(t_vector v)
{
	const double	epsilon = 1e-8;

	return ((fabs(v.x) < epsilon) \
			&& (fabs(v.y) < epsilon) \
			&& (fabs(v.z) < epsilon));
}

t_vector	v_componentwise_product(t_vector u, t_vector v)
{
	return (get_vector(u.x * v.x, u.y * v.y, u.z * v.z));
}