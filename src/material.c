#include "s_material.h"
#include <stdio.h>

t_material	get_material(t_material_type type, void	*consts)
{
	t_material	material;

	material.type = type;
	if (type == LAMBERTIAN)
	{
		material.constants.lambertian = *(t_lambertian *)consts;
	}
	else if (type == METAL)
	{
		material.constants.metal = *(t_metal *)consts;
	}
	else if (type == DIELECTRIC)
	{
		material.constants.dielectric = *(t_dielectric *)consts;
	}
	return (material);
}
