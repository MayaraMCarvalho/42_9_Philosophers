# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 18:36:14 by macarval          #+#    #+#              #
#    Updated: 2023/11/22 16:53:08 by macarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

FILES			= philo.c create.c life.c threads.c time.c utils.c

FILES_PATH		= src
OBJS_PATH		= obj
VPATH			= src/
HEADERS			= philo.h
CFLAGS			= -g3 -Wall -Wextra -Werror -pthread -lpthread
CC				= cc
RM				= rm -rf

OBJS			= $(addprefix $(OBJS_PATH)/, $(FILES:.c=.o))

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "Philosophers created!!"

$(OBJS_PATH):
				@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: %.c $(HEADERS) | $(OBJS_PATH)
				@$(CC) -g $(CFLAGS) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@echo "clean Done!"

fclean:			clean
				@$(RM) $(NAME) $(OBJS_PATH)
				@echo "fclean Done!"

re:				fclean all

.PHONY: 		all clean fclean re
