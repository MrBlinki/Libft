NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
get_next_line.c get_next_line_utils.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c ft_printf_formats.c ft_printf_hex.c ft_printf.c \
ft_utoa.c ft_utohex.c ft_atol.c
#Each source file, ".c" replaced by ".o"
OBJ_DIR = .obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

#Targets that aren't files
.PHONY : all clean fclean re bonus

all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
	mkdir -p $@

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

#Each .o file depends on the .c with the same name
$(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

# Testing part
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	BSDFLAG = -lbsd
endif

.PHONY : test tclean re

test : a.out

a.out : $(OBJ) tester.o
	$(CC) $(CFLAGS) $(OBJ) tester.o -o $@ $(BSDFLAG)

tester.o : tester.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
tclean : clean
	rm -f tester.o
	rm -f a.out