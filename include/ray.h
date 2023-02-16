#ifndef RAY_H
# define RAY_H

/** USER DEFINED HEADER **/
# include "s_object_array.h"
# include "s_vector.h"
# include "s_ray.h"

/** FUNCTION **/
t_ray	get_ray(t_point origin, t_vector dir);
t_point	ray_at(t_ray *ray, double t);
t_color	ray_color(t_ray *r, t_object_array *world, int depth);

#endif