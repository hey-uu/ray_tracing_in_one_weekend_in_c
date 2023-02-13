#include "sphere.h"
#include "world.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

t_error	init_object_array(t_obj_arr *arr, int alloc_size)
{
	arr->content = malloc(sizeof(t_content) * alloc_size);
	if (!arr->content)
		return (ERROR);
	arr->type = malloc(sizeof(t_obj_type) * alloc_size);
	if (!arr->type)
	{
		free(arr->content);
		return (ERROR);
	}
	arr->alloc_size = alloc_size;
	arr->used_size = 0;
	arr->iter = 0;
	return (ERROR_NONE);
}

t_obj_arr	*create_object_array(int alloc_size)
{
	t_obj_arr	*new;

	new = malloc(sizeof(t_obj_arr));
	if (!new)
		return (NULL);
	if (init_object_array(new, alloc_size) == ERROR)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static t_error	_grow_object_array(t_obj_arr *arr)
{
	const int	new_alloc_size = arr->alloc_size * 2;
	t_obj_type	*new_type_arr;
	t_content	*new_content_arr;

	new_type_arr = malloc(sizeof(t_obj_type) * new_alloc_size);
	if (!new_type_arr)
		return (ERROR);
	new_content_arr = malloc(sizeof(t_content) * new_alloc_size);
	if (!new_content_arr)
	{
		free(new_type_arr);
		return (ERROR);
	}
	memcpy(new_type_arr, arr->type, sizeof(t_obj_type) * arr->used_size);
	memcpy(new_content_arr, arr->content, sizeof(t_content) * arr->used_size);
	arr->alloc_size = new_alloc_size;
	free(arr->type);
	free(arr->content);
	arr->type = new_type_arr;
	arr->content = new_content_arr;
	return (ERROR_NONE);
}

void	flush_object_array(t_obj_arr *arr)
{
	free(arr->content);
	free(arr->type);
	arr->content = NULL;
	arr->type = NULL;
	arr->alloc_size = 0;
	arr->used_size = 0;
	arr->iter = 0;
}

void	destroy_object_array(t_obj_arr **arr)
{
	flush_object_array(*arr);
	free(*arr);
	*arr = NULL;
}

t_error	object_add(t_obj_arr *arr, void *object, t_obj_type type)
{
	if (arr->alloc_size == arr->used_size)
	{
		if (_grow_object_array(arr) == ERROR)
			return (ERROR);
	}
	arr->type[arr->used_size] = type;
	if (type == OBJ_SPHERE)
		arr->content[arr->used_size].s = *((t_sphere *)object);
	arr->used_size++;
	return (ERROR_NONE);
}

t_bool	object_hit(\
		t_obj_arr *arr, t_ray *r, t_hit_record *record, double t_min, double t_max)
{
	t_bool	res;

	res = FALSE;
	if (arr->type[arr->iter] == OBJ_SPHERE)
	{
		res = sphere_hit(&arr->content[arr->iter].s, r, record, t_min, t_max);
	}
	else
	{
	}
	return (res);
}

t_bool	object_array_hit(\
		t_obj_arr *arr, t_ray *r, t_hit_record *record, \
		double t_min, double t_max)
{
	t_bool			hit_anything;
	t_hit_record	temp_record;
	double			closest_so_far;

	hit_anything = FALSE;
	closest_so_far = t_max;
	arr->iter = 0;
	while (arr->iter < arr->used_size)
	{
		if (object_hit(arr, r, &temp_record, t_min, closest_so_far) == TRUE)
		{
			hit_anything = TRUE;
			closest_so_far = temp_record.t;
			*record = temp_record;
		}
		arr->iter++;
	}
	return (hit_anything);
}