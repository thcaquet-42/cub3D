#ifndef PARSING_H
# define PARSING_H

#include <unistd.h>
#include <fcntl.h>

#define ERROR_PATH_MAP "PATH MAP ERROR\n"
#define ERROR_RGB "ERROR : NO DEFINE COLOR\n"
#define ERROR_MULTI_TEX "ERROR : MULTI DEFINE TEXTURE\n"
#define ERROR_LOAD_TEX "ERROR : FAILE LOAD TEXTURE\n"
#define ERROR_LOAD "ERROR LOAD\n"
#define ERROR_ARG "ERROR BAD ARGUMENT\n"
#define ERROR_MAP "ERROR BAD ARGUMENT MAP\n"

#define ERROR_MALLOC "ERROR MALLOC\n"



typedef struct s_data t_data;

void	parsing(const char *path, t_data *data);
void	search_map(t_data *data, char *line);
void	pars_map(t_data *data);

// load 

void	load_colors(char *line, int i, t_data *data, int color);
void	load_tex(char *line, int len, t_data *data, int cardinal);

// set

void	set_data(t_data *data);



#endif
