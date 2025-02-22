# **************************************************************************** #
#                                                                              #
#    Makefile - Fract-ol                                                       #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -O3 -march=native
ifdef DEBUG
	CFLAGS += -g
endif

RM      = rm -f
SANITIZE= -fsanitize=address

LDFLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit

INCLUDES = -I ./inc -I ./libs/libft -I ./libs/ft_printf -I ./libs/MLX42/include/MLX42

PRINTF = ./libs/ft_printf/build/libftprintf.a
LIBFT  = ./libs/libft/build/libft.a
MLX    = ./libs/MLX42/build/libmlx42.a
LIBS   = $(LIBFT) $(PRINTF) $(MLX)


SRC = $(wildcard *.c)


BUILD_DIR = build


OBJ = $(SRC:src/%.c=$(BUILD_DIR)/%.o)


DEF_COLOR = \033[0;39m
GREEN     = \033[0;92m
YELLOW    = \033[0;93m
BLUE      = \033[0;94m

all: $(NAME)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(SANITIZE) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBS)
	@echo " Launching Fract-ol build sequence... 🚀 "
	@$(CC) $(CFLAGS) $(SANITIZE) $(OBJ) $(LIBS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN) Fract-ol successfully built! Time to explore! 🌌$(DEF_COLOR)"

$(MLX):
	@$(MAKE) -C ./libs/MLX42

$(LIBFT):
	@$(MAKE) -C ./libs/libft

$(PRINTF):
	@$(MAKE) -C ./libs/ft_printf

debug:
	@$(MAKE) DEBUG=1
	@echo " Debug mode enabled. 🔍🐛 D"

rebug: fclean debug

clean:
	@$(RM) $(OBJ)
	@echo "$(YELLOW) Object files removed. 🧹 $(DEF_COLOR)"


fclean: clean
	@$(MAKE) -C ./libs/libft fclean
	@$(MAKE) -C ./libs/ft_printf fclean
	@$(RM) $(NAME)
	@$(RM) -r $(BUILD_DIR)
	@echo "$(BLUE) Wiped everything. 🗑️ $(DEF_COLOR)"


re: fclean
	@echo " Rebuilding from scratch... 🏗️"
	@$(MAKE) -C ./libs/ft_printf re
	@$(MAKE) -C ./libs/libft re
	@$(MAKE) all
