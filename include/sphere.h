#ifndef SPHERE_H
# define SPHERE_H

# include "constant.h"
# include "s_vector.h"
# include "s_hit_record.h"
# include "s_ray.h"
# include "s_sphere.h"

t_sphere	get_sphere(t_point center, double radius, t_material material);
t_bool		hit_sphere(\
			t_sphere *s, t_ray *r, t_hit_record *record, \
			double t_min, double t_max);
void		sphere_set_face_normal(\
			t_hit_record *record, t_ray *r, t_vector outward_mornal);

#endif