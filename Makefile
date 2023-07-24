CC = cc
MLX_PATH = ./minilibx-linux
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = so_long
# MLXFLAGS =  -L /usr/local/lib/ -lmlx -lXext -lX11
MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -lmlx -lXext -lX11

SRCS = main.c error.c
OBJS = $(SRCS:.c=.o)
INCLUDE_DIR = -I $(MLX_PATH)

# Compile source files into into object files
%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
