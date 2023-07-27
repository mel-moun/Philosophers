# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 14:54:41 by mel-moun          #+#    #+#              #
#    Updated: 2023/06/04 15:23:09 by mel-moun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = activities.c allocation.c arguments.c philo.c the_end.c time.c activities_suppot.c
CC = cc
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re