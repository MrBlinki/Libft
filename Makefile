NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c
#Each source file, ".c" replaced by ".o"
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

#Targets that aren't files
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	ar -r $(NAME) $(OBJ)

#Each .o file depends on the .c with the same name
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

# Testing part
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	BSDFLAG = -lbsd
endif

.PHONY : test tclean

test : a.out

a.out : $(OBJ) tester.o
	$(CC) $(CFLAGS) $(OBJ) tester.o -o $@ $(BSDFLAG)

tester.o : tester.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
tclean : clean
	rm -f tester.o
	rm -f a.out