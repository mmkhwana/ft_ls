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

OBJECTS =	change/ft_node.o change/ft_node.o \
			config/ft_config_arange.o config/ft_arange_sec.o config/ft_arange_first.o config/ft_arange.o \
			display/ft_perminfo.o display/ft_timeperm.o display/ft_display.o \
			flags/ft_defineflags.o flags/ft_flagfault.o flags/ft_flagparam.o flags/ft_flagtype.o flags/ft_flag.o \
			free/ft_freelist.o free/ft_freelistprv.o free/ft_free.o \
			order/ft_orderedinsert.o order/ft_insertionorder.o \
			lists/ft_list.o lists/ft_filllist.o lists/ft_newlist.o lists/ft_reverse.o \
			options/ft_listOptions.o options/ft_optionsA.o options/ft_optionB.o options/ft_optionsSetup.o options/ft_option.o \
			path/ft_makepath.o \
			printperm/ft_permission.o printperm/ft_memberperm.o printperm/ft_diffperm.o printperm/ft_printperm.o \
			sections/ft_sectionsetup.o sections/ft_displaysection.o sections/ft_section.o \
			sorttime/ft_sort_time_insert.o sorttime/ft_sort_time_inserted.o \
			time/ft_timesorted.o time/ft_timeaccessed.o \
			verify/ft_directory.o verify/ft_check.o verify/ft_linkpath.o
 
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
