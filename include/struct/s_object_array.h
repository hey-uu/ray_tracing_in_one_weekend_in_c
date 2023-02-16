#ifndef S_OBJECT_ARRAY_H
# define S_OBJECT_ARRAY_H

# include "s_material.h"
# include "s_sphere.h"

enum e_object_type
{
	OBJ_SPHERE,
};

union u_object
{
	t_sphere	s;

};

typedef enum e_object_type		t_object_type;
typedef union u_object			t_object;

struct s_object_array
{
	t_object_type	*type;
	t_object		*objects;
	int				alloc_size;
	int				used_size;
	int				iter;
};

typedef struct s_object_array	t_object_array;

#endif