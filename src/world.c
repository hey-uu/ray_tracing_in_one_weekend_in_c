#include "sphere.h"
#include "world.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

t_error	init_object_array(t_object_array *world, int alloc_size)
{
	world->objects = malloc(sizeof(t_object) * alloc_size);
	if (!world->objects)
		return (ERROR);
	world->type = malloc(sizeof(t_object_type) * alloc_size);
	if (!world->type)
	{
		free(world->objects);
		return (ERROR);
	}
	world->alloc_size = alloc_size;
	world->used_size = 0;
	world->iter = 0;
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

static t_error	_grow_object_array(t_object_array *world)
{
	const int		new_alloc_size = world->alloc_size * 2;
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
	memcpy(new_type_arr, world->type, sizeof(t_object_type) * world->used_size);
	memcpy(new_content_arr, world->objects, sizeof(t_object) * world->used_size);
	world->alloc_size = new_alloc_size;
	free(world->type);
	free(world->objects);
	world->type = new_type_arr;
	world->objects = new_content_arr;
	return (ERROR_NONE);
}

void	flush_object_array(t_object_array *world)
{
	free(world->objects);
	free(world->type);
	world->objects = NULL;
	world->type = NULL;
	world->alloc_size = 0;
	world->used_size = 0;
	world->iter = 0;
}

void	destroy_object_array(t_object_array *world)
{
	flush_object_array(world);
	free(world);
}

t_error	add_object(t_object_array *world, void *objects, t_object_type type)
{
	if (world->alloc_size == world->used_size)
	{
		if (_grow_object_array(world) == ERROR)
			return (ERROR);
	}
	world->type[world->used_size] = type;
	if (type == OBJ_SPHERE)
		world->objects[world->used_size].s = *((t_sphere *)objects);
	world->used_size++;
	return (ERROR_NONE);
}

t_bool	hit_object(\
		t_object_array *world, t_ray *ray, t_hit_record *record, \
		double t_min, double t_max)
{
	t_bool	res;

	res = FALSE;
	if (world->type[world->iter] == OBJ_SPHERE)
	{
		res = hit_sphere(\
			&world->objects[world->iter].s, ray, record, t_min, t_max);
	}
	else
	{
	}
	return (res);
}

t_bool	hit_world(\
		t_object_array *world, t_ray *ray, t_hit_record *record, \
		double t_min, double t_max)
{
	t_bool			hit_anything;
	t_hit_record	temp_record;
	double			closest_so_far;

	hit_anything = FALSE;
	closest_so_far = t_max;
	world->iter = 0;
	while (world->iter < world->used_size)
	{
		if (hit_object(world, ray, &temp_record, t_min, closest_so_far) == TRUE)
		{
			hit_anything = TRUE;
			closest_so_far = temp_record.t;
			*record = temp_record;
		}
		world->iter++;
	}
	return (hit_anything);
}
