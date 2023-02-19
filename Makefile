# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
BUILD	= \e[38;5;225m
SEP		= \e[38;5;120m
DUCK	= \e[38;5;227m
RESET	= \033[0m

NAME = miniRT

SRCS = ./srcs/*.c \
		./utils/*.c

CFLAGS	= gcc -Wall -Wextra -Werror 

MLXFLAGS = -lmlx -framework openGL -framework AppKit

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRCS)
	@$(CFLAGS) $(MLXFLAGS) $(SRCS) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)
				
re : fclean all

.PHONY : all clean fclean re
