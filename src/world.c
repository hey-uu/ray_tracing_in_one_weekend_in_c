#include "sphere.h"
#include "world.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

t_error	init_object_array(t_object_array *arr, int alloc_size)
{
	arr->objects = malloc(sizeof(t_object) * alloc_size);
	if (!arr->objects)
		return (ERROR);
	arr->type = malloc(sizeof(t_object_type) * alloc_size);
	if (!arr->type)
	{
		free(arr->objects);
		return (ERROR);
	}
	arr->alloc_size = alloc_size;
	arr->used_size = 0;
	arr->iter = 0;
	return (ERROR_NONE);
}

t_object_array	*create_object_array(int alloc_size)
{
	t_object_array	*new;

	new = malloc(sizeof(t_object_array));
	if (!new)
		return (NULL);
	if (init_object_array(new, alloc_size) == ERROR)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static t_error	_grow_object_array(t_object_array *arr)
{
	const int		new_alloc_size = arr->alloc_size * 2;
	t_object_type	*new_type_arr;
	t_object		*new_content_arr;

	new_type_arr = malloc(sizeof(t_object_type) * new_alloc_size);
	if (!new_type_arr)
		return (ERROR);
	new_content_arr = malloc(sizeof(t_object) * new_alloc_size);
	if (!new_content_arr)
	{
		free(new_type_arr);
		return (ERROR);
	}
	memcpy(new_type_arr, arr->type, sizeof(t_object_type) * arr->used_size);
	memcpy(new_content_arr, arr->objects, sizeof(t_object) * arr->used_size);
	arr->alloc_size = new_alloc_size;
	free(arr->type);
	free(arr->objects);
	arr->type = new_type_arr;
	arr->objects = new_content_arr;
	return (ERROR_NONE);
}

void	flush_object_array(t_object_array *arr)
{
	free(arr->objects);
	free(arr->type);
	arr->objects = NULL;
	arr->type = NULL;
	arr->alloc_size = 0;
	arr->used_size = 0;
	arr->iter = 0;
}

void	destroy_object_array(t_object_array **arr)
{
	flush_object_array(*arr);
	free(*arr);
	*arr = NULL;
}

t_error	object_add(t_object_array *arr, void *objects, t_object_type type)
{
	if (arr->alloc_size == arr->used_size)
	{
		if (_grow_object_array(arr) == ERROR)
			return (ERROR);
	}
	arr->type[arr->used_size] = type;
	if (type == OBJ_SPHERE)
		arr->objects[arr->used_size].s = *((t_sphere *)objects);
	arr->used_size++;
	return (ERROR_NONE);
}

t_bool	object_hit(\
		t_object_array *arr, t_ray *ray, t_hit_record *record, \
		double t_min, double t_max)
{
	t_bool	res;

	res = FALSE;
	if (arr->type[arr->iter] == OBJ_SPHERE)
	{
		res = sphere_hit(&arr->objects[arr->iter].s, ray, record, t_min, t_max);
	}
	else
	{
	}
	return (res);
}

t_bool	object_array_hit(\
		t_object_array *arr, t_ray *ray, t_hit_record *record, \
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
		if (object_hit(arr, ray, &temp_record, t_min, closest_so_far) == TRUE)
		{
			hit_anything = TRUE;
			closest_so_far = temp_record.t;
			*record = temp_record;
		}
		arr->iter++;
	}
	return (hit_anything);
}
