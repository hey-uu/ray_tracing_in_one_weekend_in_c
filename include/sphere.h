#ifndef SPHERE_H
# define SPHERE_H

# include "constant.h"
# include "s_vector.h"
# include "s_hit_record.h"
# include "s_ray.h"
# include "s_sphere.h"

t_sphere	sphere(t_pt3 center, double radius);
t_bool		sphere_hit(\
			t_sphere *s, t_ray *r, t_hit_record *record, \
			double t_min, double t_max);
t_color		sphere_color(t_sphere *s, t_ray *r);
void		sphere_set_face_normal(\
			t_hit_record *record, t_ray *r, t_vec3 outward_mornal);


#endif