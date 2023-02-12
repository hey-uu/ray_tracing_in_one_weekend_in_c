#ifndef S_SPHERE_H
# define S_SPHERE_H

# include "s_vector.h"
# include "s_hit_record.h"

typedef struct s_sphere
{
	t_pt3			center;
	double			radius;
}	t_sphere;


#endif