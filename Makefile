NAME = out/client out/server
SRC = main programs/client programs/server utils/send utils/receive
SRCS = $(addsuffix .c, $(addprefix src/, $(SRC)))
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))
LIBFT = ../libft/libft.a
INCLUDES = -I $(CURDIR)/incl -I $(CURDIR)/libft
CODAM_FLAGS = -Wall -Wextra -Werror -g

COLOR_INFO = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_YELLOW = \033[1;33m
COLOR_ORANGE = \033[1;31m
COLOR_RESET = \033[0m

EMOJI_INFO = 🌈
EMOJI_SUCCESS = 🎉
EMOJI_CLEAN = 🧹
EMOJI_RUN = 🚀

all: create_folders $(NAME)
	@if [ "$(NORUN)" != "1" ]; then \
		$(MAKE) run; \
	fi

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(COLOR_INFO)🔨  Compiling client...$(COLOR_RESET)"
	@cc $(OBJS) $(LIBFT) $(INCLUDES) $(LINKERS) $(CODAM_FLAGS) -o out/client
	@echo "$(COLOR_INFO)🔨  Compiling server...$(COLOR_RESET)"
	@cc $(OBJS) $(LIBFT) $(INCLUDES) $(LINKERS) $(CODAM_FLAGS) -o out/server

$(OBJS): incl/minitalk.h

build/%.o: src/%.c
	@tput reset
	@mkdir -p $(@D)
	@gcc $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(COLOR_INFO)🪄  Building Libft...$(COLOR_RESET)"
	@$(MAKE) -C ../libft > /dev/null
	@echo "$(COLOR_SUCCESS)$(EMOJI_SUCCESS)  Libft built successfully!$(COLOR_RESET)"

create_folders:
	@mkdir -p out
	@mkdir -p $(dir $(OBJS))

clean:
	@echo "$(COLOR_YELLOW)🔥  Cleaning up...$(COLOR_RESET)"
	@$(MAKE) -C ../libft clean > /dev/null
	@rm -rf build
	@echo "$(COLOR_ORANGE)🧨  Cleaned up the cache!$(COLOR_RESET)"

fclean: clean
	@echo "$(COLOR_YELLOW)🔥  Removing executable...$(COLOR_RESET)"
	@$(MAKE) -C ../libft fclean > /dev/null
	@rm -f $(NAME)
	@echo "$(COLOR_ORANGE)🧨  Executable removed!$(COLOR_RESET)"

run: $(NAME) $(MLX) $(LIBFT) $(OBJS)
	@echo "$(COLOR_INFO)$(EMOJI_RUN)  Starting the server!$(COLOR_RESET)\n\n"
	@./out/server

re: fclean $(NAME)
	# @if [ "$(NORUN)" != "1" ]; then \
	# 	$(MAKE) run; \
	# fi

.PHONY: all clean fclean run re create_folders

.SILENT: all $(NAME) mlx clean fclean run re create_folders
