# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 23:44:59 by zbabahmi          #+#    #+#              #
#    Updated: 2023/10/03 23:51:32 by zbabahmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = @cc
CFLAGS = -Wall -Werror -Wextra
SRC = alloc.c main.c utils.c
OBJ = $(SRC:.c=.o)
RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all