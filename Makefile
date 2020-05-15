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
EXE = ft_ls
MAIN = main.c

CC = gcc

SOURCE =	change/ft_node.c change/ft_node.c \
			config/ft_config_arange.c config/ft_arange_sec.c config/ft_arange_first.c config/ft_arange.c \
			display/ft_perminfo.c display/ft_timeperm.c display/ft_display.c \
			flags/ft_defineflags.c flags/ft_flagfault.c flags/ft_flagparam.c flags/ft_flagtype.c flags/ft_flag.c \
			free/ft_freelist.c free/ft_freelistprv.c free/ft_free.c \
			order/ft_orderedinsert.c order/ft_insertionorder.c \
			lists/ft_list.c lists/ft_filllist.c lists/ft_newlist.c lists/ft_reverse.c \
			options/ft_listOptions.c options/ft_optionsA.c options/ft_optionB.c options/ft_optionsSetup.c options/ft_option.c \
			path/ft_makepath.c \
			printperm/ft_permission.c printperm/ft_memberperm.c printperm/ft_diffperm.c printperm/ft_printperm.c \
			sections/ft_sectionsetup.c sections/ft_displaysection.c sections/ft_section.c \
			sorttime/ft_sort_time_insert.c sorttime/ft_sort_time_inserted.c \
			time/ft_timesorted.c time/ft_timeaccessed.c \
			verify/ft_directory.c verify/ft_check.c verify/ft_linkpath.c

OBJECTS =	ft_node.o ft_node.o \
			ft_config_arange.o ft_arange_sec.o ft_arange_first.o ft_arange.o \
			ft_perminfo.o ft_timeperm.o ft_display.o \
			ft_defineflags.o ft_flagfault.o ft_flagparam.o ft_flagtype.o ft_flag.o \
			ft_freelist.o ft_freelistprv.o ft_free.o \
			ft_orderedinsert.o ft_insertionorder.o \
			ft_list.o ft_filllist.o ft_newlist.o ft_reverse.o \
			ft_listOptions.o ft_optionsA.o ft_optionB.o ft_optionsSetup.o ft_option.o \
			ft_makepath.o \
			ft_permission.o ft_memberperm.o ft_diffperm.o ft_printperm.o \
			ft_sectionsetup.o ft_displaysection.o ft_section.o \
			ft_sort_time_insert.o ft_sort_time_inserted.o \
			ft_timesorted.o ft_timeaccessed.o \
			ft_directory.o ft_check.o ft_linkpath.o
 
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
	$(CC) $(FLAG) -o $(EXE) $(MAIN) $(NAME)
	#$(CC) $(FLAGS) main.c $(NAME)
