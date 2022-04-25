# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <antoine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 09:56:55 by anloisea          #+#    #+#              #
#    Updated: 2022/04/23 16:36:51 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= prog
SRCS	= get_next_line.c get_next_line_utils.c main.c
BSRCS	= get_next_line_bonus.c	get_next_line_utils_bonus.c main.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
CFLAGS	=  -g -Wall -Werror -Wextra -D BUFFER_SIZE=5
CC		= gcc
BONUS	= bonus

all:	${NAME}

.c.o:
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} -fsanitize=address ${CFLAGS}  ${OBJS} -o ${NAME}

${BONUS}:	${BOBJS}
	${CC} -fsanitize=address ${CFLAGS} ${BOBJS} -o ${BONUS}

clean:
	rm -f ${OBJS} ${BOBJS}

fclean:	clean
	rm -f ${NAME} ${BONUS}

re:	fclean all
