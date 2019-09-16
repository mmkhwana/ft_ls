# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmkhwana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 09:11:33 by mmkhwana          #+#    #+#              #
#    Updated: 2019/09/16 17:59:20 by mmkhwana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls.a

CC = gcc

SOURCE = ft_permissions.c ft_perminfo.c ft_timeperm.c

OBJECTS = ft_permissions.o ft_perminfo.c ft_timeperm.o

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) -c $(SOURCE)
	make -C libft/ re
	ar rc $(NAME) $(OBJECTS) libft/*.o
	ranlib $(NAME)


re : fclean $(NAME)

clean : 
	rm -rf $(OBJECTS) libft/*.o


fclean : clean
	rm -rf $(NAME) libft/libft.a
	rm -rf .*.swp libft/.*.swp

c:
	$(CC) $(FLAGS) main.c $(NAME)
