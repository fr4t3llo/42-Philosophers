# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 17:30:01 by skasmi            #+#    #+#              #
#    Updated: 2022/07/07 17:48:41 by skasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=philo_bonus
NAME2=philo_bonus.h

SRCS=philo_bonus.c ft_routine.c philo_utils.c philo_utils_2.c ft_check_error.c \
		check_error.c ft_create_node.c ft_libft_fun.c ft_libft_function.c \

BOBJCTS=$(BSRCS:%.c=%.o)

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS) $(NAME2)
		$(CC) $(CFLAGS)  $(OBJCTS) -o $(NAME) 

all: $(NAME)

bonus : $(BOBJCTS)
				$(CC) $(CFLAGS)  $(BOBJCTS) -o

clean:	
				rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
				rm -f $(NAME)

re: fclean all  