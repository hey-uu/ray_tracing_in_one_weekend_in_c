#ifndef S_INFO_H
# define S_INFO_H

# include "s_image.h"
# include "s_camera.h"
# include "s_object_array.h"

struct s_info
{
	t_image			image;
	t_camera		camera;
	t_object_array	world;
};

typedef struct s_info	t_info;

#endif