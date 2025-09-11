#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include "libft/libft.h"

// lib pas sur de les garder la :

#include <stdio.h>
#include <string.h>
#include <sys/time.h>

// a voir si ca reste ou pas

#include "parsing.h"
// #include "mlx/MLX42.h"

#define TRUE 1
#define FALSE 0

typedef struct s_path // une struct temporaire, elle vas bientot etre modifier
{
	int	NO;
	int	SO;
	int	WE;
	int	EA;
}t_path;

typedef struct s_point
{
	double	x;
	double	y;
}t_point;

typedef struct s_int_point
{
	int	x;
	int	y;
}t_int_point;

typedef struct s_vec
{
	t_point	pos;
	t_point	dir;
}t_vec;

typedef struct s_data
{
	// mlx_t		*mlx;
	t_vec		player;
	t_point		cam;
	t_int_point	map_size;
	char		**map;
	int			scrn_x;
	int			scrn_y;

	// mes ajout ================
	t_path	tex;
	int		F[3];
	int		C[3];
}t_data;


// tools 

void	tool_exit(int nb_exit, char *str, t_data *data, void *thing);


// function

#endif

