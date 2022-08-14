# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 20:20:42 by ywadday           #+#    #+#              #
#    Updated: 2022/08/14 01:12:42 by ywadday          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEADER = philo.h

SRC = philo.c\
	init_philo.c\
	create_philos.c\
	utils.c\

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) 
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all 