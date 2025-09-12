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
#include "MLX42/include/MLX42/MLX42.h"

#define TRUE 1
#define FALSE 0
#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define F 0
#define C 1


typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

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
	t_vec			player;
	t_point			cam;
	t_int_point		map_size;
	char			**map;
	int				scrn_x;
	int				scrn_y;

	// mes ajout ================
	mlx_texture_t	*tex[4];
	t_color			rgb[2];
}t_data;


// tools 

void		tool_exit(int nb_exit, char *str, t_data *data, void *thing);
uint32_t	tool_rgba(int r, int g, int b, int a);

// check

int			check_case_map(int c);

// function

#endif

