NAME	= my_sokoban

CC	= gcc

RM	= rm -f

SRCS	= ./sokoban.c \
		  ./erreur.c \
		  ./idkwhy.c \
		  ./my_putchar.c \
		  ./my_putnbr.c \
		  ./my_putstr.c \
		  ./backslash.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -lncurses -g

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all