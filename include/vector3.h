
#ifndef VECTOR3_H
# define VECTOR3_H

/** STANDARD HEADER FILE **/
# include <math.h>

/** USER DEFINED HEADER FILE **/
# include "s_vector.h"
# include "constant.h"

/** FUNCTIONS **/

// vector constructor
t_vector	get_vector(double x, double y, double z);
t_point		get_point(double x, double y, double z);
t_vector	get_reflect_vector(t_vector v, t_vector n);
t_vector	get_refract_vector(t_vector i, t_vector n, double r_idx_ratio);

// vector operator
t_vector	v_add(t_vector u, t_vector v);
t_vector	v_subtract(t_vector u, t_vector v);
t_vector	v_mul(t_vector v, double t);
t_vector	v_div(t_vector v, double t);
double		v_len(t_vector v);
double		v_len_sqr(t_vector v);
t_vector	get_unit_vector(t_vector v);
double		v_dot_product(t_vector u, t_vector v);
t_vector	v_cross_product(t_vector u, t_vector v);
t_bool		v_near_zero(t_vector v);
t_vector	v_componentwise_product(t_vector u, t_vector v);

// random vector
t_vector	random_vector(double min, double max);
t_vector	random_in_unit_sphere(void);
t_vector	random_on_unit_sphere(void);

#endif