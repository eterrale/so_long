CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

HEADER = libft.h

SRC =  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c ft_strdup.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strncmp.c \
	ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_toupper.c \
	ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlcpy.c ft_substr.c ft_atoi.c ft_strnstr.c \
	ft_strlcat.c

BONUS_SRCS =  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) # Create the static library from object files

%.o: %.c ${HEADER}
	@$(CC) $(CFLAGS) -c $< -o $@

bonus = .bonus

bonus: $(NAME) $(BONUS_OBJS)
	@ar rcs $(NAME) $(BONUS_OBJS)
	@touch .bonus

clean:
	@rm -f $(OBJ) $(BONUS_OBJS)
	@rm -f .bonus
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
