#ifndef RAY_H
# define RAY_H

/** USER DEFINED HEADER **/
# include "s_object_array.h"
# include "s_vector.h"
# include "s_ray.h"

/** FUNCTION **/
t_ray	ray(t_pt3 origin, t_vec3 dir);
t_pt3	ray_at(t_ray *ray, double t);
t_color	ray_color(t_ray *r, t_obj_arr *world, int depth);


#endif