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
		  ft_diffperm.c ft_display.c ft_path.c ft_sort_time.c ft_sort_time_b.c ft_newlist.c
		  ft_fill_list.c  ft_list.c	  

OBJECTS = ft_permission.o ft_perminfo.c ft_timeperm.o ft_printperm.o ft_memberperm.o
		  ft_diffperm.o ft_display.o ft_path.o ft_sort_time.o ft_sort_time_b.c ft_newlist.o
		  ft_fill_list.o  ft_list.o
 
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
