# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:38:58 by aanghel           #+#    #+#              #
#    Updated: 2022/12/28 19:13:46 by aanghel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SRCS = Libft/gnl/get_next_line.c \
	   Libft/printf/*.c \
	   Libft/ft_is/*.c \
	   Libft/ft_lst/*.c \
	   Libft/ft_mem/*.c \
	   Libft/ft_put/*.c \
	   Libft/ft_str/*.c \
	   Libft/ft_to/*.c \
	   src/*.c \

OBJS = $(SRC:%.c=%.o)

CC = gcc

FLAGS = #-Wall -Werror -Wextra

MLX = -l mlx -framework openGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re