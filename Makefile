# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:38:58 by aanghel           #+#    #+#              #
#    Updated: 2023/01/08 05:01:21 by pcatapan         ###   ########.fr        #
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
	   src/parsing/*.c \
	   src/free/*.c \
	   src/shape/*.c \
	   src/vector/*.c \

OBJS = $(SRC:%.c=%.o)

CC = gcc

FLAGS = #-Wall -Werror -Wextra

MLX = -l mlx -framework openGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(FLAGS) $(MLX) $(SRCS) -o $(NAME)

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf minirt.dSYM 

re: fclean all

.PHONY: all clean fclean re