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

SOURCE = ft_permission.c ft_perminfo.c ft_timeperm.c ft_printperm.c ft_memberperm.c
		  ft_diffperm.c ft_display.c

OBJECTS = ft_permission.o ft_perminfo.c ft_timeperm.o ft_printperm.o ft_memberperm.o
		  ft_diffperm.o ft_display.o

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
