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

#include "parsing/parsing.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define TRUE 1
#define FALSE 0
#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define F 0
#define C 1

#define MAP_X 200
#define MAP_Y 200


typedef struct s_color
{
	int r;
	int g;
	int b;
}t_color;

typedef struct s_point
{
	double	x;
	double	y;
}t_point;

typedef struct s_vec
{
	t_point	pos;
	t_point	dir;
}t_vec;

typedef struct s_lst
{
	struct s_lst	*next;
	char		*str;
}	t_lst;

typedef struct s_arrow
{
	t_point front;
	t_point back;
	t_point side;
	t_point sym;
}t_arrow;

typedef struct s_tail
{
	struct s_lst	*start;
	struct s_lst	*end;
	size_t			min;
	size_t			x;
	size_t			y;
}	t_tail;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t *minimap;
	t_vec			player;
	t_point			cam;
	char			**map;
	int				scrn_x;
	int				scrn_y;

	// mes ajout ================
	mlx_texture_t	*tex[4];
	t_color			rgb[2];
	t_tail			lst_map;
	int				fd;
}t_data;


// tools 

uint32_t	tool_rgba(int r, int g, int b, int a);

// clear
void		clear_exit(int nb_exit, char *str, t_data *data, void *thing);
void		clear_data(t_data *data);
t_lst		*clear_lst(t_data *data);

// lst
void	lst_add_back(t_tail *tail, char *content, size_t n);
t_tail	lst_set();

// check
int			check_is_void(int c);
int			check_case_map(int c);
int			check_is_spawn(int c);
int			check_is_walkable(int c);

// =============================================

// vec
t_point new_point(double x, double y);

// loop
void game_loop(void *arg);

// draw
void draw_map(t_data *data);
// function

#endif
