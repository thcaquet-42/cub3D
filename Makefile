NAME		= cub3D

SRC			= 	src/main.c	\
				src/hooks.c \
				\
				\
				src/parsing/parsing_map.c \
				src/parsing/parsing.c \
				src/parsing/set.c \
				src/parsing/load.c \
				\
				\
				src/tools/tools0.c \
				src/tools/short_check.c \
				src/tools/lst.c \
				src/tools/clear.c \
				\
				\
				src/rendering/draw.c \
				src/rendering/loop.c \
				src/rendering/dda.c \
				\
				\
				src/key/key.c\
				\
				\


SRC_B		= 	src_bonnus/main.c	\
				src_bonnus/hooks.c \
				\
				\
				src_bonnus/parsing/parsing_map.c \
				src_bonnus/parsing/parsing.c \
				src_bonnus/parsing/set.c \
				src_bonnus/parsing/load.c \
				\
				\
				src_bonnus/tools/tools0.c \
				src_bonnus/tools/short_check.c \
				src_bonnus/tools/lst.c \
				src_bonnus/tools/clear.c \
				\
				\
				src_bonnus/rendering/draw.c \
				src_bonnus/rendering/loop.c \
				src_bonnus/rendering/dda.c \
				\
				\
				src_bonnus/key/key.c\
				\
				\


				
OBJ			= $(SRC:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)

LIB_PATH	= src/libft
LIB			= $(LIB_PATH)/libft.a

CFLAGS		= -Werror -Wextra -Wall -g
LDFLAGS		= -I $(LIB_PATH)/ 

MLX_LIB 	= minilibx-linux/libmlx_Linux.a

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIB) $(MLX_LIB) -lX11 -lXext -lm -o $(NAME)

$(NAME_B): $(OBJ_B)
	cc $(CFLAGS) $(OBJ_B) $(LIB) $(MLX_LIB) -lX11 -lXext -lm -o $(NAME_B)

$(LIB):
	make -sC $(LIB_PATH)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

all: $(LIB) $(NAME)

bonnus: $(lib) $(NAME_B)

clean:
	rm -f $(OBJ)
	make -sC $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -sC $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonnus
