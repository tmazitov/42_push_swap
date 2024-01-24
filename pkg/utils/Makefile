LIBRARY := utils.a

SRCS := ft_atoi.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_split.c \
		ft_strchr.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_substr.c \
		ft_strcmp.c 

OBJS := $(SRCS:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

GREEN := \033[0;32m
NC := \033[0m

$(LIBRARY): $(OBJS)
	ar rcs $@ $^
	@echo "$(GREEN)---- Utils build successful!$(NC)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "$(GREEN)---- Utils clean successful!$(NC)"

fclean: clean
	rm -f $(LIBRARY)
	@echo "$(GREEN)---- Utils clean all successful!$(NC)"
