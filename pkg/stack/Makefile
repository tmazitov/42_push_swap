LIBRARY := libstack.a

PRINTF := cd ../printf && make

SRCS := stack.c \
		stack_node.c \
		stack_opera_pop.c \
		stack_opera_push.c \
		stack_opera_swap.c \
		stack_opera_rotate.c \
		stack_opera_rotate_reverse.c \
		stack_opera_includes.c \
		stack_utils.c 

OBJS := $(SRCS:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

GREEN := \033[0;32m
NC := \033[0m

$(LIBRARY): $(OBJS)
	$(PRINTF)
	ar rcs $@ $^
	@echo "$(GREEN)---- Libstack build successful!$(NC)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:	
	cd ../printf && make clean
	rm -f $(OBJS)
	@echo "$(GREEN)---- Libstack clean successful!$(NC)"

fclean: clean
	cd ../printf && make fclean
	rm -f $(LIBRARY)
	@echo "$(GREEN)---- Libstack clean all successful!$(NC)"
