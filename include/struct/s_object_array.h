#ifndef S_OBJECT_ARRAY_H
# define S_OBJECT_ARRAY_H

# include "s_sphere.h"

enum e_object_type
{
	OBJ_SPHERE,
};

union u_content
{
	t_sphere	s;

};

typedef enum e_object_type	t_obj_type;
typedef union u_content		t_content;

struct s_object_array
{
	t_obj_type	*type;
	t_content	*content;
	int			used_size;
	int			alloc_size;
	int			iter;
};

typedef struct s_object_array	t_obj_arr;

#endif