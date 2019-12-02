# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mminkjan <mminkjan@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/12 11:46:52 by mminkjan       #+#    #+#                 #
#    Updated: 2019/06/06 19:42:58 by mminkjan      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FTS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	  ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
	  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_memcmp.c ft_strncmp.c ft_strlcat.c
FTS2 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	   ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
	   ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c
FTS3 = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c
BONUS = ft_str_epu.c ft_iswhitespace.c ft_wordcount.c ft_countdigits.c ft_nametag.c \
		ft_lstaddback.c
ADDS = get_next_line.c
FILES = $(FTS) $(FTS2) $(FTS3) $(BONUS) $(ADDS)
BIN = $(FTS:.c=.o) $(FTS2:.c=.o) $(FTS3:.c=.o) $(BONUS:.c=.o) $(ADDS:.c=.o)
FLAGS = -Wall  -Wextra -Werror

all : $(NAME)

$(NAME) :
	@ gcc $(FLAGS) -c -I includes $(FILES)
	@ ar rc $(NAME) $(BIN)
	@ ranlib $(NAME)
	
clean :
	@ rm -f $(BIN)
	@ rm -f *#
	@ rm -f *~

fclean : clean
	@ rm -f $(NAME)

re : fclean all

