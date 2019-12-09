# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mminkjan <mminkjan@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/05 15:48:04 by mminkjan       #+#    #+#                 #
#    Updated: 2019/12/09 16:25:03 by mminkjan      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -o 

MLX = minilibx_macos/

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/

SRCS = ./srcs/
SRCS_FILE = main mlx_setup utilities import_map calculate_points map_manager \
			save_input draw_line rotate_point calculate_color

CFILES =  $(SRCS_FILE:%=$(SRCS)%.c)

HFILES = includes/fdf.h

FILES = author Makefile


all : $(NAME)

$(NAME) :
	@make re -C $(LIBFT)
	@gcc -I $(MLX) -L $(MLX) $(MLXFLAGS) -I $(LIBFT) -L $(LIBFT) -lft $(CFILES) \
	$(FLAGS) $(NAME)

clean :
	@make clean -C $(LIBFT)
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