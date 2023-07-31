# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 18:13:22 by marvin            #+#    #+#              #
#    Updated: 2023/07/30 20:11:48 by dnishsha         ###   ########.fr        #
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

SRCS = main.c error.c validate_map.c $(GET_NEXT_LINE_DIR)/get_next_line.c $(GET_NEXT_LINE_DIR)/get_next_line_utils.c validate_map_utils.c \
	save_map.c map_solution.c render_window.c render_map.c movements.c
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
