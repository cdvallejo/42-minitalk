# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 09:58:38 by cvallejo          #+#    #+#              #
#    Updated: 2022/09/09 11:28:29 by cvallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJS_SERVER = ${SRC_SERVER:.c=.o}
OBJS_CLIENT = ${SRC_CLIENT:.c=.o}
NAME_SERVER = server
NAME_CLIENT = client

#BONUS#
SRC_SERVER_BONUS = server_bonus.c
SRC_SERVER_CLIENT = client_bonus.c
OBJS_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}
OBJS_CLIENT_BONUS = ${SRC_SERVER_CLIENT:.c=.o}
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

#COMPILATION UTILS#
LIBRARY = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#RULES#
.c.o:
	${CC} ${FLAGS} -c $< -o $@

all: norminette libft server client

norminette: 
	@echo "\n *** CHECKING 42 NORMINETTE ***\n"
	@norminette server.c client.c server_bonus.c client_bonus.c

libft: 
	@echo "\n *** COMPILING LIBFT ***\n"
	@${MAKE} -C ./libft/

compile: ${NAME_SERVER} ${NAME_CLIENT}

$(NAME_SERVER): ${OBJS_SERVER}
	@echo "\n *** COMPILING SERVER PROGRAM ***\n"
	@${CC} ${OBJS_SERVER} ${LIBRARY} -o ${NAME_SERVER}

$(NAME_CLIENT): ${OBJS_CLIENT}
	@echo "\n *** COMPILING CLIENT PROGRAM ***\n"
	@${CC} ${OBJS_CLIENT} ${LIBRARY} -o ${NAME_CLIENT}

#BONUS RULES#

bonus: norminette libft compile_bonus

compile_bonus: ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

$(NAME_SERVER_BONUS): ${OBJS_SERVER_BONUS}
	@echo "\n *** COMPILING SERVER BONUS PROGRAM ***\n"
	@${CC} ${OBJS_SERVER_BONUS} ${LIBRARY} -o ${NAME_SERVER}

$(NAME_CLIENT_BONUS): ${OBJS_CLIENT_BONUS}
	@echo "\n *** COMPILING CLIENT BONUS PROGRAM ***\n"
	@${CC} ${OBJS_CLIENT_BONUS} ${LIBRARY} -o ${NAME_CLIENT}

#CLEAN RULES#

clean:
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS_SERVER} ${OBJS_CLIENT} 
	@${RM} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}

fclean: clean
	@${MAKE} -C ./libft fclean
	@${RM} ${NAME_CLIENT} ${NAME_SERVER} ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}
	@${RM} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}

re: fclean all

.PHONY: all clean fclean re libft compile norminette