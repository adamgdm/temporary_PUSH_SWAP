CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_MDTORY = check.c helpers_1.c helpers_2.c helpers_3.c helpers_4.c helpers_5.c helpers_6.c \
              helpers_7.c makestack.c push_swap.c sort.c Operations/Helpers.c Operations/Op_double.c \
              Operations/push.c Operations/reverse_rotate.c Operations/rotate.c \
              Operations/swap.c sort_more.c ft_printf/Library/ft_putchar_fd.c ft_printf/Library/ft_putnbr_fd.c \
              ft_printf/Library/ft_putu_fd.c ft_printf/Library/ft_printp_fd.c \
              ft_printf/Library/ft_puthex_fd.c ft_printf/Library/ft_putstr_fd.c \
              ft_printf/ft_printf.c
       
SRCS_BONUSF = Bonus/check.c Bonus/Checker.c Bonus/GET_NEXT_LINE/get_next_line.c \
              Bonus/GET_NEXT_LINE/get_next_line_utils.c Bonus/helpers_1.c Bonus/helpers_2.c \
              Bonus/helpers_3.c Bonus/helpers_4.c Bonus/makestack.c \
              Bonus/Operations/Helpers.c Bonus/Operations/Op_double.c Bonus/Operations/push.c \
              Bonus/Operations/reverse_rotate.c Bonus/Operations/rotate.c \
              Bonus/Operations/swap.c ft_printf/Library/ft_putchar_fd.c ft_printf/Library/ft_putnbr_fd.c \
              ft_printf/Library/ft_putu_fd.c ft_printf/Library/ft_printp_fd.c \
              ft_printf/Library/ft_puthex_fd.c ft_printf/Library/ft_putstr_fd.c \
              ft_printf/ft_printf.c

OBJS = $(SRCS_MDTORY:.c=.o)
BONUS_OBJS = $(SRCS_BONUSF:.c=.o)

OBJSS = 

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

bonus: $(BONUS_OBJS) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) 

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(OBJS_PRINTF)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) $(OBJS_PRINTF)

re: fclean all

.PHONY: all bonus clean fclean re
