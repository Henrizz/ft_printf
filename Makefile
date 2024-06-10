NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c printoutfunctions.c ptr_conv.c hex_conv.c
OBJS = $(SRCS:.c=.o)
AR = ar rc
RM = rm -rf
CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

%.o : %.c
	cc $(CFLAGS) -c $^ -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
