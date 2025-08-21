#======================= VARIABLES =======================
NAME = libft.a

#Tous tes fichiers .c
SRC  = ft_isalpha.c \
       ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \

SRC_BONUS  = ft_lstnew_bonus.c \
	   ft_lstadd_front_bonus.c \
	   ft_lstsize_bonus.c \
	   ft_lstlast_bonus.c \
	   ft_lstadd_back_bonus.c \
	   ft_lstdelone_bonus.c \
	   ft_lstclear_bonus.c \
	   ft_lstiter_bonus.c \
	   ft_lstmap_bonus.c \

#Convertit automatiquement chaque .c → .o
OBJ  = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# ======================= RÈGLES ==========================
#Règle par défaut : taper simplement "make" lancera "all"
all: $(NAME)

#Comment fabriquer libft.a ?
$(NAME): $(OBJ)
	$(AR) $@ $^

#Comment fabriquer un .o depuis un .c ?
%.o: %.c
	cc $(CFLAGS) -c $< -o $@

#Nettoyer les .o
clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

#Nettoyer .o + lib
fclean: clean
	$(RM) $(NAME)

bonus: $(OBJ_BONUS) $(NAME)
	$(AR) $(NAME) $(OBJ_BONUS)

#Recompiler proprement
re: fclean all

#Déclare ces noms comme « pas de vrais fichiers »
.PHONY: all clean fclean re
