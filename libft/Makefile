NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

# compiler
CC = cc

#List of source files
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_strdup.c \
ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# This creates a list of object files to be generated from the source files.
OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

# Command to produce the executable with the object files as an input.
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus:  $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)

# Build each object file from its corresponding source file.
# '-c' option tells the compiler to generate object files from source files, without linking them into an executable
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) ${OBJS_BONUS}

fclean: clean
	rm -f $(NAME)

# 're' ("rebuild" / "recompile") target is typically used to clean the build directory and rebuild the entire project from scratch.
# When you run make re, Make will execute the clean target to remove all generated files and then execute the all target to rebuild the entire project from scratch.
re: fclean all

.PHONY: re bonus all fclean clean
