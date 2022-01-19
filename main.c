/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/01/19 15:02:10 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list	*head;
	char	*result;
	int		lstlen;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit source_file\n", 2);
		return (-1);
	}
	lstlen = 0;
	head = read_file(argv, &lstlen);
	if (head == NULL)
	{
		ft_putstr_fd("error\n", 2);
		return (-1);
	}
	result = solver(head, lstlen * EL_SIZE);
	print_result(result);
	return (0);
}

//run: gcc -Wall -Werror -Wextra -I. main.c solver.c print_result.c
// read_file.c structure_functions.c  -L libft/ -lft 