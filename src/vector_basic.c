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
