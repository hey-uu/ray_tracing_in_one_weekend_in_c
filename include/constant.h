#ifndef CONSTANT_H
# define CONSTANT_H

# include <limits.h>

// t range
# define T_MINIMUM				0.001
# define T_INFINITY 			INT_MAX

// sampling
# define SAMPLES_PER_PIXEL		100

// recursive count
# define MAX_DEPTH				50

// image
# define IMG_WIDTH				400
# define IMG_ASPECT_RATIO		(double)16.0 / 9.0

// object
# define MATERIAL_NUMBER		3
# define OBJECT_NUMBER			4
// camera
# define FOCAL_LENGTH			1
# define FIELD_OF_VIEW			40
# define UP_VECTOR				(t_vector){0, 1, 0}
# define LOOK_FROM				(t_point){-2, 2, 1}
# define LOOK_AT				(t_point){0, 0, -1}


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