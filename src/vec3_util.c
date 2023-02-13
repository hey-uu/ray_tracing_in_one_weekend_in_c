
#include "vector3.h"
#include "utils.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	random_vec3(double min, double max)
{
	return (vec3(random_double_interval(min, max), \
				random_double_interval(min, max), \
				random_double_interval(min, max)));
}

// random vector in unit sphere
t_vec3	random_vec3_in_unit_sphere(void)
{
	t_vec3	random_point;

	while (1)
	{
		random_point = random_vec3(-1, 1);
		if (v3_len_sqr(random_point) >= 1)
			continue ;
		return (random_point);
	}
}

t_vec3	random_unit_vec3(void)
{
	return (v3_unit(random_vec3_in_unit_sphere()));
}

t_pt3	point3(double x, double y, double z)
{
	return ((t_pt3)vec3(x, y, z));
}
