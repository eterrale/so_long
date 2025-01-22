CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(MINILIB_DIR) -lmlx -lXext -lX11

NAME = so_long

MAIN_SRC = main.c close_game.c get_next_line.c load_map.c free_map.c init_window.c \
			load_background.c

SRC = $(MAIN_SRC)

MINILIB_DIR = minilibx
LIBFT_DIR = libft
MINILIB = $(MINILIB_DIR)/libmlx_Linux.a
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = so_long.h $(MINILIB_DIR)/mlx.h $(MINILIB_DIR)/mlx_int.h $(LIBFT_DIR)/libft.h

OBJS_DIR = objects
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

all: $(LIBFT) $(MINILIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIB)
		@echo "Creating $(NAME)..."
		@$(CC) $(OBJS) $(LIBFT) $(MINILIB) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(HEADERS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(HEADERS)
		@echo "Building libft..."
		$(MAKE) -C $(LIBFT_DIR) all

$(MINILIB): $(HEADERS)
		@echo "Building minilib..."
		$(MAKE) -C $(MINILIB_DIR) all

clean:
		@echo "Cleaning object files..."
		@rm -rf $(OBJS_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean
		@$(MAKE) -C $(MINILIB_DIR) clean

fclean: clean
		@echo "Cleaning binaries..."
		@rm -rf $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: all clean fclean re