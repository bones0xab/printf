



CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
AR = ar rcs
SRC = ft_printf.c ft_printf_printers.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean
