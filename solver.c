/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/01/15 10:20:30 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	clear_result(char **result, char clear)
{
	int	i;

	i = 0;
	while (*(*result + i) != '\0')
	{
		if (*(*result + i) == clear)
			*(*result + i) = O_CHAR;
		i++;
	}
}

static int	place_element(t_list *head, int sqr, char **result)
{
	int	i;
	int	loc;

	i = -1;
	while (++i < EL_SIZE)
	{
		loc = head->cur_pos + head->x[i] + head->y[i] * sqr;
		if (*(*result + loc) == O_CHAR && head->cur_pos % sqr + head->x[i] \
			< sqr && head->cur_pos / sqr + head->y[i] < sqr)
			*(*result + loc) = head->symbol;
		else
		{
			clear_result(result, head->symbol);
			return (0);
		}
	}
	return (1);
}

static int	solve(t_list *head, char **result, int sqr)
{
	int	solution;

	while (head)
	{
		solution = 1;
		while (head->cur_pos < sqr * sqr && !place_element(head, sqr, result))
			head->cur_pos++;
		if (head->cur_pos == sqr * sqr)
		{
			head->cur_pos = 0;
			head = head->prev;
			if (head)
			{
				clear_result(result, head->symbol);
				head->cur_pos++;
			}
			solution = 0;
		}
		else
			head = head->next;
	}
	return (solution);
}

char	*solver(t_list *head, int min_size)
{
	char	*result;
	int		sqr;

	sqr = 2;
	while (sqr * sqr < min_size)
		sqr++;
	result = ft_strnew(sqr * sqr);
	result = ft_memset(result, O_CHAR, sqr * sqr);
	while (solve(head, &result, sqr) == 0)
	{
		ft_strdel(&result);
		sqr++;
		result = ft_strnew(sqr * sqr);
		result = ft_memset(result, O_CHAR, sqr * sqr);
	}
	return (result);
}
