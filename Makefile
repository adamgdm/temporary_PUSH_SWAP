CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf/ft_printf.c ft_printf/Library/ft_printp_fd.c ft_printf/Library/ft_putchar_fd.c \
       ft_printf/Library/ft_puthex_fd.c ft_printf/Library/ft_putnbr_fd.c \
       ft_printf/Library/ft_putstr_fd.c ft_printf/Library/ft_putu_fd.c \
	   check.c helpers_1.c helpers_2.c \
       helpers_3.c helpers_4.c makestack.c Operations/Helpers.c \
       Operations/Op_double.c Operations/push.c Operations/reverse_rotate.c \
       Operations/rotate.c Operations/swap.c push_swap.c sort.c sort_more.c

BONUS_SRCS = Bonus/check.c Bonus/Checker.c Bonus/GET_NEXT_LINE/get_next_line.c \
             Bonus/GET_NEXT_LINE/get_next_line_utils.c Bonus/helpers_1.c \
             Bonus/helpers_2.c Bonus/helpers_3.c Bonus/helpers_4.c \
             Bonus/makestack.c Bonus/Operations/Helpers.c \
             Bonus/Operations/Op_double.c Bonus/Operations/push.c \
             Bonus/Operations/reverse_rotate.c Bonus/Operations/rotate.c \
             Bonus/Operations/swap.c ft_printf/ft_printf.c \
             ft_printf/Library/ft_printp_fd.c ft_printf/Library/ft_putchar_fd.c \
             ft_printf/Library/ft_puthex_fd.c ft_printf/Library/ft_putnbr_fd.c \
             ft_printf/Library/ft_putstr_fd.c ft_printf/Library/ft_putu_fd.c \
             helpers_5.c helpers_6.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
