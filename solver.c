/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/10/11 15:48:07 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Go through all possible positions in a line to place the piece. If the piece
** fits, place it. Otherwise, go to next line and repeat.
*/
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

/*
** Iterate through all pieces and try to place them. If the piece is placed, go
** to the next piece and try to place it in a free spot. If the piece can not be
** placed, go to the previous piece and move it to the next place. Repeat until
** either a solution was found or no valid solution exists.
*/
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

/*
** Creation of a 16x16 map to place the pieces. Initial check of minimum
** square size. Increase square size until a solution is found.
*/
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
