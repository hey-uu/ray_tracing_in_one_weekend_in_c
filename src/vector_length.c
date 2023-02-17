#include "vector3.h"

double	v_len(t_vector v)
{
	return (sqrt((v.x * v.x + v.y * v.y + v.z * v.z)));
}

double	v_len_sqr(t_vector v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_bool	v_near_zero(t_vector v)
{
	const double	epsilon = 1e-8;

	return ((fabs(v.x) < epsilon) \
			&& (fabs(v.y) < epsilon) \
			&& (fabs(v.z) < epsilon));
}
