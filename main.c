/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/01/18 22:44:12 by manuelbeele      ###   ########.fr       */
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
//		ft_putstr_fd(2, "USAGE");
		return (-1);
	}
	lstlen = 0;
	head = read_file(argv, &lstlen);
	result = solver(head, lstlen * EL_SIZE);
	print_result(result);
	system("leaks a.out"); //
	return (0);
}

//run: gcc -Wall -Werror -Wextra -I. main.c solver.c print_result.c read_file.c structure_functions.c  -L libft/ -lft 