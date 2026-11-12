NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a
INC			= -I $(LIBFT_DIR)

SRCS		= main.c \
			  parsing.c \
			  parsing_numbers.c \
			  parsing_int.c \
			  stack.c \
			  operations.c \
			  disorder.c \
			  algo_simple.c \
			  algo_medium.c \
			  algo_complex.c \
			  algo_adaptive.c \
			  bench.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
