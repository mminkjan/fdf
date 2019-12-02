# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mminkjan <mminkjan@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/05 15:48:04 by mminkjan       #+#    #+#                 #
#    Updated: 2019/12/02 17:31:00 by mminkjan      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -o 

MLX = minilibx_macos/

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/

SCRS = ./scrs/
SCRS_FILE = main

CFILES =  $(SCRS_FILE:%=$(SCRS)%.c)

HFILES = ./includes/fdf.h

FILES = author Makefile


all : $(NAME)

$(NAME) :
	@make re -C $(LIBFT)
	@gcc -I $(MLX) -L $(MLX) $(MLXFLAGS) -I $(LIBFT) -L $(LIBFT) -lft $(CFILES) \
	$(FLAGS) $(NAME)

clean :
	@make clean -C $(LIBFT)
	@rm -f minilibx_macos/*.o
	@rm -f *#
	@rm -f *~
	@rm -f .DS_Store
	@rm -Rf .vscode

fclean : clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re : fclean all

add : fclean
	@ git add $(MLX) $(LIBFT) $(CFILES) $(HFILES) $(FILES)
	@ git status

push :
ifdef MSG
	@ git commit -m "$(MSG)"
	@ git push -u origin
	# @ git push -u gitt
else 
    @ echo "usage ex: make push MSG="<message>"
endif
