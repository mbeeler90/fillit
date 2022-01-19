# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 15:54:37 by jjuntune          #+#    #+#              #
#    Updated: 2022/01/19 14:39:08 by jjuntune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = main.c print_result.c read_file.c solver.c structure_functions.c

OFILES = $(FILES:.c=.o)

LIBRERY = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	gcc $(FLAGS) -o $(NAME) $(OFILES) $(LIBRERY)
%.o:%.c
	gcc $(FLAGS) -c $(FILES) $<
clean:
	rm -f $(OFILES)
fclean: clean
	rm -rf $(NAME)
re: fclean all