#include "vector3.h"

double	v_dot_product(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vector	v_cross_product(t_vector u, t_vector v)
{
	return (get_vector(u.y * v.z - u.z * v.y, \
				u.z * v.x - u.x * v.z, \
				u.x * v.y - u.y * v.x));
}

t_vector	v_componentwise_product(t_vector u, t_vector v)
{
	return (get_vector(u.x * v.x, u.y * v.y, u.z * v.z));
}
