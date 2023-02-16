#include "discriminant.h"
#include <math.h>

t_discr	get_discriminant(double a, double b, double c)
{
	t_discr	d;

	d.a = a;
	d.b = b;
	d.c = c;
	d.discriminant = b * b - a * c;
	if (d.discriminant >= 0)
	{
		d.sqrtd = sqrt(d.discriminant);
		d.root1 = (-b - d.sqrtd) / a;
		d.root2 = (-b + d.sqrtd) / a;
	}
	return (d);
}
