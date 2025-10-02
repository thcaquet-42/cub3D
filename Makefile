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
				src/rendering/vec.c \
				\
				\
				src/key/key.c\
				\
				\



				
OBJ			= $(SRC:.c=.o)

LIB_PATH	= src/libft
LIB			= $(LIB_PATH)/libft.a

CFLAGS		= -Werror -Wextra -Wall -g
LDFLAGS		= -I $(LIB_PATH)/ 

MLX_LIB 	= minilibx-linux/libmlx_Linux.a


all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIB) $(MLX_LIB) -lX11 -lXext -lm -o $(NAME)

$(LIB):
	make -sC $(LIB_PATH)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make -sC $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -sC $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
