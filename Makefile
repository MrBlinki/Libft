NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	ar -r $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

# Testing part
.PHONY : test tclean

test : a.out

a.out : $(OBJ) tester.o
	$(CC) $(CFLAGS) $(OBJ) tester.o -o $@

tester.o : tester.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
tclean :
	rm -f $(OBJ)
	rm -f tester.o
	rm -f a.out