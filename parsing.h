#ifndef PARSING_H
# define PARSING_H

#include <unistd.h>
#include <fcntl.h>

#define ERROR_PATH_MAP "PATH MAP ERROR\n"
#define ERROR_RGB "ERROR : DEFINE COLOR\n"
#define ERROR_MULTI_TEX "ERROR : MULTI DEFINE TEXTURE\n"
#define ERROR_LOAD_TEX "ERROR : FAILE LOAD TEXTURE\n"
#define ERROR_LOAD "ERROR LOAD\n"
#define ERROR_ARG "ERROR BAD ARGUMENT \n"
#define ERROR_MAP "ERROR BAD ARGUMENT MAP \n"



typedef struct s_lst
{
	struct s_lst	*next;
	char			*str;
}	t_lst;

typedef struct s_tail
{
	struct s_lst	*start;
	struct s_lst	*end;
	size_t			x;
	size_t			y;
}	t_tail;



typedef struct s_data t_data;

void	parsing(const char *path, t_data *data);

// load 

void	load_colors(char *line, int i, t_data *data, int color);
void	load_tex(char *line, int len, t_data *data, int cardinal);

// set

void	set_data(t_data *data);

// tools
// lst
void	lst_add_back(t_tail *tail, char *content);
t_tail	lst_set();

#endif
