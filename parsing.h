#ifndef PARSING_H
# define PARSING_H

#include <unistd.h>
#include <fcntl.h>

#define ERROR_PATH_MAP "PATH MAP ERROR\n"
#define ERROR_MULTI_PATH "MULTI PATH ERROR\n"
#define ERROR_PATH "PATH ERROR\n"
#define ERROR_LOAD "ERROR LOAD\n"





typedef struct s_data t_data;

void	parsing(const char *path, t_data *data);

// set

void	set_data(t_data *data);

#endif
