/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/01/23 19:38:50 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	place_element(t_list *head, int sqr, unsigned short int *map)
{
	while (head->x + head->width < sqr)
	{
		if (!(*(unsigned long long int *)(map + head->y)
			& (head->code >> head->x)))
		{
			*(unsigned long long int *)(map + head->y)
				^= (head->code >> head->x);
			head->cur_pos = head->x + head->y * sqr;
			return (1);
		}
		head->x++;
	}
	head->x = 0;
	return (0);
}

static int	solve(t_list *head, unsigned short int *map, int sqr)
{
	int	solution;

	while (head)
	{
		solution = 1;
		while (head->y + head->height < sqr && !place_element(head, sqr, map))
			head->y++;
		if (head->y + head->height == sqr)
		{
			head->y = 0;
			head = head->prev;
			if (head)
			{
				*(unsigned long long int *)(map + head->y)
					^= (head->code >> head->x);
				head->x++;
			}
			solution = 0;
		}
		else
			head = head->next;
	}
	return (solution);
}

int	solver(t_list *head, int min_size)
{
	unsigned short int	map[16];
	int					sqr;

	sqr = 2;
	while (sqr * sqr < min_size)
		sqr++;
	ft_bzero(map, sizeof(short int) * 16);
	while (solve(head, map, sqr) == 0)
		sqr++;
	return (sqr);
}
