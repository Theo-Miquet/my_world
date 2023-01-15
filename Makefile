##
## EPITECH PROJECT, 2019
## makefile
## File description:
## world
##

NAME	= my_world

CC	= gcc -l csfml-graphics -l csfml-system -l csfml-window -lm -g

RM	= rm -f

SRCS	= $(wildcard ./src/*.c ./lib/my/*.c)

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
