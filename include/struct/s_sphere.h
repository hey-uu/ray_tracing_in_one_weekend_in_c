#ifndef S_SPHERE_H
# define S_SPHERE_H

# include "s_vector.h"
# include "s_hit_record.h"

typedef struct s_sphere
{
	t_point		center;
	double		radius;
	t_material	material;
}	t_sphere;

#endif