NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c
OBJ = $(SRC:.c=.o)	# Each source file, ".c" replaced by ".o"

CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re	# Targets that aren't files

all : $(NAME)

$(NAME) : $(OBJ)
	ar -r $(NAME) $(OBJ)

%.o : %.c	# Each .o file depends on the .c with the same name
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
	
tclean : clean
	rm -f tester.o
	rm -f a.out