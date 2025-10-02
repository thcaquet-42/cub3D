#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>


#include "libft/libft.h"

// lib pas sur de les garder la :

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <X11/Xutil.h>

// a voir si ca reste ou pas

#include "parsing/parsing.h"
#include "../minilibx-linux/mlx.h"

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

#define WIDTH 1920
#define HEIGHT 1080

#define BKEY_W 1
#define BKEY_A 2
#define BKEY_S 4
#define BKEY_D 8
#define BKEY_LEFT  16
#define BKEY_RIGHT 32

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307
#define KEY_LEFT  65361
#define KEY_RIGHT 65363

#define PI 3.141592654
#define PI4 0.785398163
#define PI8 0.392699082
#define PI16 0.196349541
#define PI32 0.09817477


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
	double	dir;
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


typedef struct s_tex
{
	void		*img;
	uint32_t	*buf;
	int			width;
	int			height;
	int			size_w;	

} t_tex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void 		*img;
	uint32_t 	*buf;
	t_vec		player;
	t_point		cam;
	char		**map;
	int			scrn_x;
	int			scrn_y;

	// mes ajout ================
	t_tex			tex[4];
	t_color			rgb[2];
	t_tail			lst_map;
	int				fd;
	int				keys;
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

// key
int		key_hook_press(int key, void *v_data);
int		key_hook_release(int key, void *v_data);
void	key_hook(t_data *data);
int		close_window(t_data *data);

// =============================================

// vec
t_point new_point(double x, double y);

// loop
int game_loop(void *arg);

// draw
void draw_map(t_data *data);
void draw_player(t_data *data);
// function

#endif
