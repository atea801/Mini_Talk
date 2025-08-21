# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aautret <aautret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 14:15:18 by aautret           #+#    #+#              #
#    Updated: 2025/08/21 19:57:41 by aautret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER := server
NAME_CLIENT := client
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I. -I printf -I libft -D_POSIX_C_SOURCE=200809L -D_DEFAULT_SOURCE

PRINTF_SRCS   := printf/ft_printf.c \
				printf/ft_convert.c \
				printf/ft_convert_base.c

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SERVER_SRCS   := serveur.c
CLIENT_SRCS   := client.c client_utils.c

SRCS_SERVER   := $(SERVER_SRCS) $(PRINTF_SRCS)
SRCS_CLIENT   := $(CLIENT_SRCS) $(PRINTF_SRCS)

OBJS_SERVER   := $(SRCS_SERVER:.c=.o)
OBJS_CLIENT   := $(SRCS_CLIENT:.c=.o)


all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

