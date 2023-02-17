#include "vector3.h"
#include "utils.h"

t_vector	get_reflect_vector(t_vector i, t_vector n)
{
	return (v_subtract(i, v_mul(n, 2 * v_dot_product(i, n))));
}

double	reflectance(double cosine, double refract_ratio)
{
	double	r0;

	r0 = (1 - refract_ratio) / (1 + refract_ratio);
	r0 *= r0;
	return (r0 + (1 - r0) * pow(1 - cosine, 5));
}

t_vector	get_refract_vector(t_vector i, t_vector n, double refract_ratio)
{
	const double	cos_incidence = fmin(-v_dot_product(i, n), 1);
	const double	sin_incidence = sqrt(1 - cos_incidence * cos_incidence);
	t_vector		r_parallel;
	t_vector		r_perp;

	if (refract_ratio * sin_incidence > 1
		|| reflectance(cos_incidence, refract_ratio) > random_double())
		return (get_reflect_vector(i, n));
	r_perp = v_mul(v_add(i, v_mul(n, cos_incidence)), refract_ratio);
	r_parallel = v_mul(n, -sqrt(fabs(1 - v_len_sqr(r_perp))));
	return (v_add(r_parallel, r_perp));
}
