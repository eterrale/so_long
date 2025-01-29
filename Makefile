CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(MINILIB_DIR) -lmlx -lXext -lX11

NAME = so_long

SRC_DIR = src/
LIBFT_DIR = libft/
MINILIB_DIR = minilibx/

MAIN_SRC = $(SRC_DIR)main.c $(SRC_DIR)close_game.c $(SRC_DIR)get_next_line.c $(SRC_DIR)load_map.c \
		   $(SRC_DIR)free_map.c $(SRC_DIR)init_window.c $(SRC_DIR)init_ressources.c \
		   $(SRC_DIR)render_map.c $(SRC_DIR)player_move.c $(SRC_DIR)print_error.c \
		   $(SRC_DIR)check_rules_map.c $(SRC_DIR)check_map_ext.c $(SRC_DIR)check_exit_reachable.c \
		   $(SRC_DIR)check_exit_reachable_utils.c $(SRC_DIR)event_hook.c $(SRC_DIR)print_count_move.c \
		   $(LIBFT_DIR)ft_bzero.c $(LIBFT_DIR)ft_strdup.c $(LIBFT_DIR)ft_strlen.c \
		   $(LIBFT_DIR)ft_putstr_fd.c $(LIBFT_DIR)ft_split.c $(LIBFT_DIR)ft_strjoin.c

SRC = $(MAIN_SRC)

MINILIB = $(MINILIB_DIR)libmlx_Linux.a
LIBFT = $(LIBFT_DIR)libft.a

HEADERS = include/so_long.h $(MINILIB_DIR)mlx.h $(LIBFT_DIR)libft.h

OBJS_DIR = objects
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(OBJS_DIR) $(LIBFT) $(MINILIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIB) $(HEADERS)
		@echo "Creating $(NAME)..."
		@$(CC) $(OBJS) $(LIBFT) $(MINILIB) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)%.c $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(LIBFT_DIR)%.c $(HEADERS)
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
		@rm -rf $(LIBFT)
		@rm -rf $(MINILIB)

re: fclean all

.PHONY: all clean fclean re