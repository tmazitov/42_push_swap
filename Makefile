NAME := pushswap

GREEN := \033[0;32m
NC := \033[0m
CC := gcc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address

SRCS := cmd/main.c \
		internal/parsing/parsing.c \
		internal/validation/validation.c \
		internal/operations/push.c \
		internal/operations/swap.c \
		internal/operations/rotate.c \
		internal/operations/rotate_reverse.c

OBJS := $(SRCS:.c=.o)

MAKE_STACK 	:= cd pkg/stack && make
MAKE_UTILS 	:= cd pkg/utils && make

$(NAME): $(OBJS)
	$(MAKE_UTILS)
	$(MAKE_STACK)
	$(CC) $(OBJS) \
		$(CFLAGS) \
		pkg/utils/utils.a \
		pkg/stack/libstack.a \
		pkg/printf/libftprintf.a \
		-o $(NAME) 
	@echo "$(GREEN)Pushswap build successful!$(NC)"

all: $(NAME)

clean:
	cd pkg/stack && make clean
	cd pkg/utils && make clean
	rm -f $(OBJS)
	@echo "$(GREEN)Pushswap clean successful!$(NC)"

fclean: clean
	cd pkg/stack && make fclean
	cd pkg/utils && make fclean
	rm -f $(LIBRARY)
	@echo "$(GREEN)Pushswap clean all successful!$(NC)"

re:		fclean all

.PHONY: all, re, clean, fclean
