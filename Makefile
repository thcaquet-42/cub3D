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
				src/rendering/img.c \
				src/rendering/loop.c \
				src/rendering/vec.c \
				\
				\



				
OBJ			= $(SRC:.c=.o)

LIB_PATH	= src/libft
LIB			= $(LIB_PATH)/libft.a

CFLAGS		= -Werror -Wextra -Wall -g
LDFLAGS		= -I $(LIB_PATH)/ 

MLX_DIR 	= MLX42
MLX_LIB 	= $(MLX_DIR)/build/libmlx42.a


all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIB) $(MLX_LIB) -lglfw -o $(NAME)

$(LIB):
	make -sC $(LIB_PATH)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make -sC $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)
	make -sC $(LIB_PATH) fclean

re: fclean mlx all

mlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	else \
		echo "$(MLX_DIR) already exists"; \
	fi
	@echo "Building MLX42..."
	@cd $(MLX_DIR) && mkdir -p build && cd build && cmake .. && make

.PHONY: all clean fclean re mlx
