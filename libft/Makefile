# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mdekker <mdekker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/05 15:23:33 by mdekker       #+#    #+#                  #
#    Updated: 2023/06/19 15:53:32 by mdekker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re run test

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
INCLUDES=-I ./
BUILDDIR=build
SRC = characters/ft_isalpha.c characters/ft_isdigit.c characters/ft_isalnum.c characters/ft_isascii.c  \
	characters/ft_toupper.c characters/ft_tolower.c memory/ft_bzero.c memory/ft_memcmp.c memory/ft_memset.c \
	memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memchr.c memory/ft_memchr.c characters/ft_isprint.c \
	strings/ft_strlcpy.c strings/ft_strlcat.c strings/ft_strncmp.c \
	strings/ft_atoi.c strings/ft_strlen.c strings/ft_strchr.c strings/ft_strrchr.c \
	memory/ft_calloc.c strings/ft_strnstr.c strings/ft_strdup.c io/ft_putendl_fd.c io/ft_putstr_fd.c \
	io/ft_putchar_fd.c io/ft_putnbr_fd.c strings/ft_itoa.c strings/ft_striteri.c strings/ft_substr.c \
	strings/ft_strjoin.c strings/ft_strmapi.c strings/ft_strtrim.c strings/ft_split.c strings/ft_atod.c \
	strings/ft_strcat.c strings/ft_strcpy.c utils/math.c utils/string.c strings/ft_atol.c \
	strings/ft_strcmp.c

PRINTF= printf/build/put.o printf/build/printf.o printf/build/utils.o
OBJECTS=$(addprefix $(BUILDDIR)/, $(SRC:.c=.o))
FOLDERS=$(dir $(SRC))
SPLIT=$(FOLDERS:/=)
CAT=$(addprefix $(BUILDDIR)/, $(FOLDERS))

all: $(NAME)

clean:
	@echo "🧨 Cleaning build folder..."
	@rm -rf $(BUILDDIR)
	@echo "✅ Done!"

fclean: clean
	@echo "🧨 Force cleaning libft..."
	@rm -f $(NAME)
	@echo "✅ Done!"

$(BUILDDIR)/%.o: %.c | $(BUILDDIR)
	@mkdir -p $(CAT)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(PRINTF):
	make -C printf

$(GNL):
	make -C gnl

$(NAME): $(OBJECTS) $(PRINTF)
	@echo "⚙️ Compiling..."
	@ar rc $(NAME) $(OBJECTS) $(PRINTF)
	@echo "✅ Done!"

norm:
	@echo "🧐 Norm-i-netting..."
	@norminette $(SRC)
	@echo "✅ Done!"

re:
	@$(MAKE) fclean
	@$(MAKE) all
