# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aautret <aautret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 14:15:18 by aautret           #+#    #+#              #
#    Updated: 2025/08/20 17:03:12 by aautret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER := server
# NAME_CLIENT := client
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I. -I printf

PRINTF_SRCS   := printf/ft_printf.c \
				printf/ft_convert.c \
				printf/ft_convert_base.c
SERVER_SRCS   := serveur.c
# CLIENT_SRCS   := client.c

SRCS_SERVER   := $(SERVER_SRCS) $(PRINTF_SRCS)
# SRCS_CLIENT   := $(CLIENT_SRCS) $(PRINTF_SRCS)

OBJS_SERVER   := $(SRCS_SERVER:.c=.o)
# OBJS_CLIENT   := $(SRCS_CLIENT:.c=.o)


all: $(NAME_SERVER) #$(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

# $(NAME_CLIENT): $(OBJS_CLIENT)
# 	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER)

fclean: clean
	rm -f $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
