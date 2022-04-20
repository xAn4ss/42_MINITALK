# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 14:36:32 by aoukhart          #+#    #+#              #
#    Updated: 2022/04/11 15:27:21 by aoukhart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_01 = Server.c

SRC_02 = Client.c

UTILS = utils.c

NAME_SERV = server

NAME_CLIENT = client

CFLAGS = -Wall -Wextra -Werror

all : $(NAME_SERV) $(NAME_CLIENT)
	
$(NAME_SERV) : Server.o
	@gcc $(CFLAGS) $(UTILS) $(SRC_01) -o $(NAME_SERV)
	@clear

$(NAME_CLIENT) : Client.o
	@gcc $(CFLAGS) $(UTILS) $(SRC_02) -o $(NAME_CLIENT)
	@clear

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME_SERV)
	@rm -rf $(NAME_CLIENT)

re : fclean all