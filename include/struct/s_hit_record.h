#ifndef S_HIT_RECORD_H
# define S_HIT_RECORD_H

# include "s_vector.h"
# include "constant.h"
# include "s_material.h"

typedef struct s_hit_record
{
	t_point		p;
	t_vector	normal;
	double		t;
	t_material	*material;
	t_bool		front_face;
}	t_hit_record;

#endif