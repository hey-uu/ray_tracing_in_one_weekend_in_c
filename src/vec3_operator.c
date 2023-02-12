
#include "vector3.h"

t_vec3	v3_add(t_vec3 u, t_vec3 v)
{
	return (vec3(u.x + v.x, u.y + v.y, u.z + v.z));
}

t_vec3	v3_subtract(t_vec3 u, t_vec3 v)
{
	return (vec3(u.x - v.x, u.y - v.y, u.z - v.z));
}

t_vec3	v3_mul(t_vec3 v, double t)
{
	return (vec3(t * v.x, t * v.y, t * v.z));
}

t_vec3	v3_div(t_vec3 v, double t)
{
	return (vec3(v.x / t, v.y / t, v.z / t));
}

double	v3_len(t_vec3 v)
{
	return (sqrt((v.x * v.x + v.y * v.y + v.z * v.z)));
}

double	v3_len_sqr(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3	v3_unit(t_vec3 v)
{
	return (v3_div(v, v3_len(v)));
}

double	v3_dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	v3_cross_product(t_vec3 u, t_vec3 v)
{
	return (vec3(u.y * v.z - u.z * v.y, \
				u.z * v.x - u.x * v.z, \
				u.x * v.y - u.y * v.x));
}
