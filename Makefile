# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aautret <aautret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 14:15:18 by aautret           #+#    #+#              #
#    Updated: 2025/08/20 14:58:58 by aautret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minitalk

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -I. -Iprintf

# ————————————— SOURCES FT_PRINTF —————————————
PRINTF_SRCS := \
	printf/ft_printf.c \
	printf/ft_convert.c \
	printf/ft_convert_base.c

SERVEUR_SRCS := \
	serveur.c \



SRCS	:= push_swap.c $(PRINTF_SRCS) $(SERVEUR_SRCS)
OBJS	:= $(SRCS:.c=.o)


all: $(NAME)

# ————————————— RÈGLE GÉNÉRIQUE .c → .o —————————————
# Chaque .c dépend de push_swap.h et ft_printf.h
%.o: %.c push_swap.h printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# ————————————— NETTOYAGE —————————————
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) test_sa

re: fclean all

.PHONY: all clean fclean re test_sa
