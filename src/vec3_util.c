
#include "vector3.h"
#include <stdio.h>

t_pt3	point3(double x, double y, double z)
{
	return ((t_pt3)vec3(x, y, z));
}

void	v3_write(t_vec3 *v)
{
	printf("%lf %lf %lf\n", v->x, v->y, v->z);
}

