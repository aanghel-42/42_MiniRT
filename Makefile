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
