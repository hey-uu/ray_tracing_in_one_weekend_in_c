#ifndef CONSTANT_H
# define CONSTANT_H

# include <limits.h>

// t range
# define T_MINIMUM				0.001
# define T_INFINITY 			INT_MAX

// sampling
# define SAMPLES_PER_PIXEL		500

// recursive count
# define MAX_DEPTH				50

// image
# define IMG_WIDTH				1200
# define IMG_ASPECT_RATIO		(double)3.0 / 2.0

// object
# define MATERIAL_NUMBER		4
# define OBJECT_NUMBER			5
// camera
# define APERTURE				0.1
# define FOCAL_DISTANCE			10.0
# define FIELD_OF_VIEW			30
# define UP_VECTOR				(t_vector){0, 1, 0}
# define LOOK_FROM				(t_point){13, 2, 3}
# define LOOK_AT				(t_point){0, 0, 0}
// material
# define GROUND_MATERIAL		(t_lambertian){(t_color){0.5, 0.5, 0.5}}

enum e_bool
{
	FALSE,
	TRUE
};

enum e_error
{
	ERROR,
	ERROR_NONE
};

typedef enum e_bool		t_bool;
typedef enum e_error	t_error;
#endif