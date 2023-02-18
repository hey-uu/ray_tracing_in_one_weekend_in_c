#include "vector3.h"
#include "utils.h"

t_vector	random_vector(double min, double max)
{

	return (get_vector(random_double_interval(min, max), \
				random_double_interval(min, max), \
				random_double_interval(min, max)));
}

t_vector	random_in_unit_sphere(void)
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

t_vector	random_on_unit_sphere(void)
{
	return (get_unit_vector(random_in_unit_sphere()));
}

t_vector	random_in_unit_disk(void)
{
	t_vector	random;

	while (1)
	{
		random = get_vector(\
			random_double_interval(-1, 1), random_double_interval(-1, 1), 0);
		if (v_len_sqr(random) >= 1)
			continue ;
		return (random);
	}
}