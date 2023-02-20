#ifndef WORLD_H
# define WORLD_H

# include "s_object_array.h"
# include "s_ray.h"

t_error			init_object_array(t_object_array *arr, int alloc_size);
t_object_array	*create_object_array(int alloc_size);
void			flush_object_array(t_object_array *arr);
void			destroy_object_array(t_object_array *arr);
t_error			add_object(\
				t_object_array *arr, void *object, t_object_type type);
t_bool			hit_object(\
				t_object_array *arr, t_ray *r, t_hit_record *record, \
				double t_min, double t_max);
t_bool			hit_world(\
				t_object_array *arr, t_ray *r, t_hit_record *record, \
				double t_min, double t_max);

#endif