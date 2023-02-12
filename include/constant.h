#ifndef CONSTANT_H
# define CONSTANT_H

# include <limits.h>

# define T_MIN 0
# define T_INFINITY INT_MAX
# define SAMPLES_PER_PIXEL 100

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