#ifndef WORLD_H
# define WORLD_H

# include "s_object_array.h"
# include "s_ray.h"

t_error		init_object_array(t_obj_arr *arr, int alloc_size);
t_obj_arr	*create_object_array(int alloc_size);
void		flush_object_array(t_obj_arr *arr);
void		destroy_object_array(t_obj_arr **arr);
t_error		object_add(t_obj_arr *arr, void *object, t_obj_type type);
t_bool		object_hit(\
			t_obj_arr *arr, t_ray *r, t_hit_record *record, double t_min, double t_max);
t_bool		object_array_hit(\
			t_obj_arr *arr, t_ray *r, t_hit_record *record, double t_min, double t_max);

#endif