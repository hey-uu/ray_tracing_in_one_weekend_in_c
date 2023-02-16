#ifndef MATERIAL_H
# define MATERIAL_H

# include "s_material.h"

t_material	get_material(t_material_type type, void	*consts);
t_bool		scatter(\
			t_ray *ray, t_hit_record *record, \
			t_color *attenuation, t_ray *scattered);
#endif