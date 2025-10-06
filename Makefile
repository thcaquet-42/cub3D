NAME		= cub3D

SRC			= 	src/main.c	\
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

NAME_B		= cub3D_bonus


SRC_B		= 	src_bonus/main.c	\
				\
				\
				src_bonus/parsing/parsing_map.c \
				src_bonus/parsing/parsing.c \
				src_bonus/parsing/set.c \
				src_bonus/parsing/load.c \
				\
				\
				src_bonus/tools/tools0.c \
				src_bonus/tools/short_check.c \
				src_bonus/tools/lst.c \
				src_bonus/tools/clear.c \
				\
				\
				src_bonus/rendering/draw.c \
				src_bonus/rendering/loop.c \
				src_bonus/rendering/dda.c \
				\
				\
				src_bonus/key/key.c\
				\
				\

		
OBJ			= $(SRC:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)

LIB_PATH	= libft
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

all: $(LIB) $(NAME) $(NAME_B)

bonus: $(LIB) $(NAME_B)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)
	make -sC $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	make -sC $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus
