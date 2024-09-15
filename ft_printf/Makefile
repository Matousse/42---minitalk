NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_prints.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) 
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) 
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

