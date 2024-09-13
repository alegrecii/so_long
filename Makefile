NAME = so_long

SRCS = game/animation.c \
		game/check_init.c \
		game/ft_close.c \
		game/get_next_line_utils.c \
		game/get_next_line.c \
		game/ghost_manager.c \
		game/input_manager.c \
		game/map_check.c \
		game/map_manager.c \
		game/path_finder.c \
		game/so_long.c \
		game/superfree.c \
		game/updater.c \

OBJS = $(SRCS:.c=.o)

LIBS = game/libftprintf.a \
		game/libmlx.a \
		game/libmlx_Linux.a \

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext -lm


all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MFLAGS) -o $(NAME) -g

clean:
		$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re


