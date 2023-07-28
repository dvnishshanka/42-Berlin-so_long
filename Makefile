# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 18:13:22 by marvin            #+#    #+#              #
#    Updated: 2023/07/28 19:35:25 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
RM = rm -f
INCLUDE = -I include

LIBFT = libft.a
LIBFT_DIR = libft
FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line

# MLX_PATH = ./minilibx-linux

# MLXFLAGS =  -L /usr/local/lib/ -lmlx -lXext -lX11
# MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -lmlx -lXext -lX11
# INCLUDE_DIR = -I $(MLX_PATH)

SRCS = main.c error.c validate_map.c $(GET_NEXT_LINE_DIR)/get_next_line.c $(GET_NEXT_LINE_DIR)/get_next_line_utils.c validate_map_utils.c \
	save_map.c map_solution.c
OBJS = $(SRCS:.c=.o)

# Compile source files into into object files
%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -fPIE -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT_PRINTF_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(INCLUDE) $(LIBFT_DIR)/$(LIBFT) $(FT_PRINTF_DIR)/$(FT_PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make clean -C $(FT_PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
