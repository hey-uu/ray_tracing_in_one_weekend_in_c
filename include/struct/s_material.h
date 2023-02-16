#ifndef S_MATERIAL_H
# define S_MATERIAL_H

# include "s_vector.h"

enum e_material_type
{
	LAMBERTIAN,
	METAL,
	DIELECTRIC
};

struct s_lambertian
{
	t_color	albedo;
};

struct s_metal
{
	t_color	albedo;
	double	fuzz;
};

struct s_dielectric
{
	double	refractive_idx;
};

typedef struct s_lambertian			t_lambertian;
typedef struct s_metal				t_metal;
typedef struct s_dielectric			t_dielectric;

union u_material_constant
{
	t_lambertian	lambertian;
	t_metal			metal;
	t_dielectric	dielectric;
};

typedef enum e_material_type		t_material_type;
typedef union u_material_constant	t_material_constant;

struct s_material
{
	t_material_type		type;
	t_material_constant	constants;
};

typedef struct s_material			t_material;

#endif