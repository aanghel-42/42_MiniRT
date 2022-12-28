# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 22:29:02 by aanghel           #+#    #+#              #
#    Updated: 2022/12/22 18:44:45 by aanghel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRC= gnl/get_next_line.c \
	 printf/*.c \
	 ft_is/*.c \
	 ft_lst/*.c \
	 ft_mem/*.c \
	 ft_put/*.c \
	 ft_str/*.c \
	 ft_to/*.c \
	 
CC= gcc

FLAGS= -Wall -Werror -Wextra

OBJS= $(SRC:%.c=%.o)


$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	
all: $(NAME)
	
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re