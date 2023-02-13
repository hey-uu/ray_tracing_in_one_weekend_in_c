
#ifndef VECTOR3_H
# define VECTOR3_H

/** STANDARD HEADER FILE **/
# include <math.h>

/** USER DEFINED HEADER FILE **/
# include "s_vector.h"

/** FUNCTIONS **/

// vector constructor
t_vec3	vec3(double x, double y, double z);
t_vec3	random_vec3(double min, double max);

// vector operator
t_vec3	v3_add(t_vec3 u, t_vec3 v);
t_vec3	v3_subtract(t_vec3 u, t_vec3 v);
t_vec3	v3_mul(t_vec3 v, double t);
t_vec3	v3_div(t_vec3 v, double t);
double	v3_len(t_vec3 v);
double	v3_len_sqr(t_vec3 v);
t_vec3	v3_unit(t_vec3 v);
double	v3_dot(t_vec3 u, t_vec3 v);
t_vec3	v3_cross_product(t_vec3 u, t_vec3 v);

// point
t_pt3	point3(double x, double y, double z);

// random vector
t_vec3	random_vec3_in_unit_sphere(void);
t_vec3	random_unit_vec3(void);

#endif