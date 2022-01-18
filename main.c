/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/01/18 18:31:48 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	t_list	*head;
/*	t_list	*head2;
	t_list	*head3;
	t_list	*head4;
	t_list	*head5;
	t_list	*head6;
	t_list	*head7;
	t_list	*head8; */
	char	*result;
	int		lstlen;

	if (argc != 2)
	{
//		ft_putstr_fd(2, "USAGE");
		return (-1);
	}
	lstlen = 0;
	head = read_file(argv, &lstlen); // tbd how linked list is generated

/*
	argc = 0;
	argv = NULL;
	head = (t_list *)malloc(sizeof(t_list));
	head2 = (t_list *)malloc(sizeof(t_list));
	head3 = (t_list *)malloc(sizeof(t_list));
	head4 = (t_list *)malloc(sizeof(t_list));
	head5 = (t_list *)malloc(sizeof(t_list));
	head6 = (t_list *)malloc(sizeof(t_list));
	head7 = (t_list *)malloc(sizeof(t_list));
	head8 = (t_list *)malloc(sizeof(t_list));
	head->next = head2;
	head->prev = NULL;
	head->symbol = START_C;
	head->cur_pos = 0;
	head->x[0] = 0;
	head->x[1] = 0;
	head->x[2] = 1;
	head->x[3] = 1;
	head->y[0] = 0;
	head->y[1] = 1;
	head->y[2] = 1;
	head->y[3] = 2;
	head2->next = head3;
	head2->prev = head;
	head2->symbol = START_C + 1;
	head2->cur_pos = 0;
	head2->x[0] = 0;
	head2->x[1] = 1;
	head2->x[2] = 0;
	head2->x[3] = 0;
	head2->y[0] = 0;
	head2->y[1] = 0;
	head2->y[2] = 1;
	head2->y[3] = 2;
	head3->next = head4;
	head3->prev = head2;
	head3->symbol = START_C + 2;
	head3->cur_pos = 0;
	head3->x[0] = 0;
	head3->x[1] = 1;
	head3->x[2] = 0;
	head3->x[3] = 1;
	head3->y[0] = 0;
	head3->y[1] = 0;
	head3->y[2] = 1;
	head3->y[3] = 1;
	head4->next = head5;
	head4->prev = head3;
	head4->symbol = START_C + 3;
	head4->cur_pos = 0;
	head4->x[0] = 0;
	head4->x[1] = 0;
	head4->x[2] = 0;
	head4->x[3] = 0;
	head4->y[0] = 0;
	head4->y[1] = 1;
	head4->y[2] = 2;
	head4->y[3] = 3;
	head5->next = head6;
	head5->prev = head4;
	head5->symbol = START_C + 4;
	head5->cur_pos = 0;
	head5->x[0] = 1;
	head5->x[1] = 2;
	head5->x[2] = 1;
	head5->x[3] = 0;
	head5->y[0] = 0;
	head5->y[1] = 0;
	head5->y[2] = 1;
	head5->y[3] = 1;
	head6->next = head7;
	head6->prev = head5;
	head6->symbol = START_C + 5;
	head6->cur_pos = 0;
	head6->x[0] = 0;
	head6->x[1] = 1;
	head6->x[2] = 2;
	head6->x[3] = 3;
	head6->y[0] = 0;
	head6->y[1] = 0;
	head6->y[2] = 0;
	head6->y[3] = 0;
	head7->next = head8;
	head7->prev = head6;
	head7->symbol = START_C + 6;
	head7->cur_pos = 0;
	head7->x[0] = 2;
	head7->x[1] = 0;
	head7->x[2] = 1;
	head7->x[3] = 2;
	head7->y[0] = 0;
	head7->y[1] = 1;
	head7->y[2] = 1;
	head7->y[3] = 1;
	head8->next = NULL;
	head8->prev = head7;
	head8->symbol = START_C + 7;
	head8->cur_pos = 0;
	head8->x[0] = 1;
	head8->x[1] = 1;
	head8->x[2] = 1;
	head8->x[3] = 0;
	head8->y[0] = 0;
	head8->y[1] = 1;
	head8->y[2] = 2;
	head8->y[3] = 2;
*/
	result = solver(head, lstlen * EL_SIZE);
	print_result(result);
//	system("leaks fillit");
	return (0);
}

//run: gcc -Wall -Werror -Wextra -I. main.c solver.c print_result.c read_file.c structure_functions.c  -L libft/ -lft 