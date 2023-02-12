#ifndef S_HIT_RECORD_H
# define S_HIT_RECORD_H

# include "s_vector.h"
# include "constant.h"

typedef struct s_hit_record
{
	t_pt3	p;
	t_vec3	normal;
	double	t;
	t_bool	front_face;
}	t_hit_record;


#endif