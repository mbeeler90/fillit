# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 15:54:37 by jjuntune          #+#    #+#              #
#    Updated: 2022/01/21 22:46:54 by manuelbeele      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = main.c print_result.c read_file.c solver.c structure_functions.c

OFILES = $(FILES:.c=.o)

LIBRERY = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OFILES) $(LIBRERY)

%.o:%.c
	gcc $(FLAGS) -c $(FILES) $<

clean:
	rm -f $(OFILES)
	make -C libft/ clean
	
fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all
