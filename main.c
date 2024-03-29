/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/01/23 19:33:36 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list		*head;
	int			lstlen;
	int			end_of_file;
	int			fd;
	int			sqr;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit source_file\n", 1);
		return (1);
	}
	lstlen = 0;
	end_of_file = 0;
	fd = 0;
	head = read_file(argv, &lstlen, end_of_file, fd);
	if (head == NULL || lstlen > 26)
	{
		ft_putstr_fd("error\n", 1);
		return (1);
	}
	sqr = solver(head, lstlen * EL_SIZE);
	print_result(head, sqr);
	delete_structure(&head);
	return (0);
}
