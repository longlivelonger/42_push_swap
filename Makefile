NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = push_swap.c input.c utils.c minisort.c operations.c operations2.c

RM = rm -rf

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(CC) $(CFLAGS) -o $@ $(SRC:.c=.o)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(SRC:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean