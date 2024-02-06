NAME := push_swap

GREEN := \033[0;32m
NC := \033[0m
CC := gcc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address

SRCS := cmd/main.c \
		internal/parsing/parsing.c \
		internal/parsing/validation.c \
		internal/validation/validation.c \
		internal/operations/push.c \
		internal/operations/swap.c \
		internal/operations/rotate.c \
		internal/operations/rotate_reverse.c \
		internal/sort/sort.c \
		internal/sort/sort_2.c \
		internal/sort/sort_3.c \
		internal/sort/sort_fill_a.c \
		internal/sort/sort_fill_b.c \
		internal/sort/sort_make_rotate.c \
		internal/sort/sort_grade_take.c \
		internal/sort/sort_grade_put.c \
		internal/sort/sort_cheapes.c \

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
	rm -f $(NAME)
	@echo "$(GREEN)Pushswap clean all successful!$(NC)"

re:		fclean all

.PHONY: all, re, clean, fclean
