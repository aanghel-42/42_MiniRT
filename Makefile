NAME = miniRT

SRCS = 	./srcs/*.c \
	   	./lib/42_Libft/gnl/get_next_line.c \
		./lib/42_Libft/printf/*.c \
		./lib/42_Libft/ft_is/*.c \
		./lib/42_Libft/ft_lst/*.c \
		./lib/42_Libft/ft_mem/*.c \
		./lib/42_Libft/ft_put/*.c \
		./lib/42_Libft/ft_str/*.c \
		./lib/42_Libft/ft_to/*.c \
		./lib/libvector/*.c

OBJS = $(SRCS:%.c=%.o)

CC = gcc -Wall -Werror -Wextra

F_MLX = -L lib/minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

$(NAME) : $(SRCS)
	@$(CC) $(FLAGS) $(SRCS) $(F_MLX) -o $(NAME)

clean:
	@rm -f $(OBJS)
			
fclean:	clean
	@rm -rf *.dSYM
	@rm $(NAME)

re:	fclean all

.PHONY:	all clean fclean re