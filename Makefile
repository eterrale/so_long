CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(MINILIB_DIR) -lmlx -lXext -lX11

NAME = so_long

SRC_DIR = src/
MAIN_SRC = $(SRC_DIR)main.c $(SRC_DIR)close_game.c $(SRC_DIR)get_next_line.c $(SRC_DIR)load_map.c \
		   $(SRC_DIR)free_map.c $(SRC_DIR)init_window.c $(SRC_DIR)load_background.c \
		   $(SRC_DIR)init_ressources.c $(SRC_DIR)render_map.c $(SRC_DIR)player_move.c \
		   $(SRC_DIR)print_error.c $(SRC_DIR)check_rules_map.c

SRC = $(MAIN_SRC)

MINILIB_DIR = minilibx
LIBFT_DIR = libft
MINILIB = $(MINILIB_DIR)/libmlx_Linux.a
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = include/so_long.h $(MINILIB_DIR)/mlx.h $(MINILIB_DIR)/mlx_int.h $(LIBFT_DIR)/libft.h

OBJS_DIR = objects
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(OBJS_DIR) $(LIBFT) $(MINILIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIB)
		@echo "Creating $(NAME)..."
		@$(CC) $(OBJS) $(LIBFT) $(MINILIB) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)%.c $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
		@mkdir -p $(OBJS_DIR)

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

$(MINILIB):
		@$(MAKE) -C $(MINILIB_DIR)

clean:
		@echo "Cleaning object files..."
		@rm -rf $(OBJS_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean
		@$(MAKE) -C $(MINILIB_DIR) clean

fclean: clean
		@echo "Cleaning binaries..."
		@rm -rf $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean
		@$(MAKE) -C $(MINILIB_DIR) clean

re: fclean all

.PHONY: all clean fclean re