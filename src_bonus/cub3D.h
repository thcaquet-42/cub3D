/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:26:23 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/07 10:08:56 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <math.h>

# include "../libft/libft.h"

// lib pas sur de les garder la :

# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <X11/Xutil.h>

// a voir si ca reste ou pas

# include "parsing/parsing.h"
# include "../minilibx-linux/mlx.h"

# define TRUE 1
# define FALSE 0
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define COMPASS 4
# define F 0
# define C 1

# define MAP_X 200
# define MAP_Y 200

# define WIDTH 1920
# define HEIGHT 1080
// # define WIDTH 1600
// # define HEIGHT 900
// # define WIDTH 1280
// # define HEIGHT 800

# define BKEY_W 1
# define BKEY_A 2
# define BKEY_S 4
# define BKEY_D 8
# define BKEY_E 16
# define BKEY_LEFT  32
# define BKEY_RIGHT 64

# define PI 3.141592654
# define PI2 1.5707963268
# define PI4 0.785398163
# define PI8 0.392699082
# define PI16 0.196349541
# define PI32 0.09817477
# define PI42 0.074799825

# define FOV 1 // 0.57735026919
# define S 1000000

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_pointi
{
	int	x;
	int	y;
}	t_pointi;

typedef struct s_tex
{
	void		*img;
	uint32_t	*buf;
	int			width;
	int			height;
	int			size_w;
}	t_tex;

typedef struct s_door
{
	unsigned char	is : 1;
	t_pointi		map;
	t_pointi		step;
	t_point			delta_dist;
	t_point			side_dist;
	t_point			ray_dir;
	double			wall_dist;
	int				line_height;
	char			side : 1;
	int				start;
	int				end;
	int				tex_x;
	int				tex_y;
	double			wall_x;
	double			tex_step;
	double			tex_pos;
	t_tex			*tex;
}	t_door;


typedef struct s_dda
{
	t_pointi	map;
	t_pointi	step;
	t_point		delta_dist;
	t_point		side_dist;
	t_point		ray_dir;
	double		wall_dist;
	int			line_height;
	char		side : 1;
	int			start;
	int			end;
	int			tex_x;
	int			tex_y;
	double		wall_x;
	double		tex_step;
	double		tex_pos;
	t_tex		*tex;
	t_door		door;
}	t_dda;

typedef struct s_vec
{
	t_point	pos;
	t_point	dir;
	double	teta;
}	t_vec;

typedef struct s_lst
{
	struct s_lst	*next;
	char			*str;
}	t_lst;

typedef struct s_tail
{
	struct s_lst	*start;
	struct s_lst	*end;
	size_t			min;
	size_t			x;
	size_t			y;
}	t_tail;

typedef struct s_toggle
{
	unsigned char	map : 1;
	unsigned char	mous : 1;
	unsigned char	door : 1;
}	t_toggle;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	uint32_t	*buf;
	t_vec		plr;
	t_point		cam;
	char		**map;
	int			scrn_x;
	int			scrn_y;
	t_tex		tex[5];
	t_color		rgb[2];
	t_tail		lst_map;
	int			fd;
	int			keys;
	t_toggle	t_key;
}	t_data;

// tools 
uint32_t	tool_rgba(int r, int g, int b, int a);
uint32_t	tool_negative(t_color *color);
uint32_t	tool_gray(t_color *color);

// clear
void		clear_exit(int nb_exit, char *str, t_data *data, void *thing);
void		clear_data(t_data *data);
t_lst		*clear_lst(t_data *data);

// lst
void		lst_add_back(t_tail *tail, char *content, size_t n);
t_tail		lst_set(void);

// check
int			check_is_void(int c);
int			check_case_map(int c);
int			check_is_spawn(int c);
int			check_is_walkable(int c);
int			check_is_edge(int c);
int			check_is_door(int c);
int			check_is_wall(int c);

// key
int			key_hook_press(int key, void *v_data);
int			key_hook_release(int key, void *v_data);
void		key_hook(t_data *data);
int			close_window(t_data *data);

// =============================================

// loop
int			game_loop(void *arg);

// draw
void		draw_map(t_data	*data);
void		draw_player(t_data *data);
void		draw_wall(t_data *data);
void		draw_compass(t_data *data);
void		draw_door(t_data *data, t_dda *dda, t_pointi i);

//dda
void		dda_alg(t_data *data, t_dda *dda, t_point plane, int x);
void		dda_choose_tex(t_data *data, t_dda *dda);

#endif
