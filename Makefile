NAME		= cub3D

SRC			= 	main.c	\
				parsing.c \
				set.c \
				tools0.c \

				
OBJ			= $(SRC:.c=.o)

LIB_PATH	= libft
LIB			= $(LIB_PATH)/libft.a

CFLAGS		= -Werror -Wextra -Wall -g
LDFLAGS		= -I $(LIB_PATH)/ 

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIB) -l readline -o $(NAME)

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
