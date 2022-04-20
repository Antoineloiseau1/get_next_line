# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 09:56:55 by anloisea          #+#    #+#              #
#    Updated: 2022/04/15 17:29:41 by anloisea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= prog
SRCS	= get_next_line.c get_next_line_utils.c main.c
OBJS	= ${SRCS:.c=.o}
CFLAGS	= -Wall -Werror -Wextra -D BUFFER_SIZE=5
CC		= gcc

all:	${NAME}

.c.o:
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} ${CFLAGS}  ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all
