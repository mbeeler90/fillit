/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/01/14 20:26:58 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	clear_result(char **result, char clear)
{
	int	i;

	i = -1;
	while (*result[++i] != '\0')
	{
		if (*result[i] == clear)
			*result[i] = O_CHAR;
	}
}

static int	place_element(t_list *head, int sqr, char **result)
{
	int	i;
	int	loc;

	if (*result[head->cur_pos] != O_CHAR)
		return (0);
	else if (head->cur_pos / sqr + head->y[2] >= sqr - 1)
		return (0);
	else if (head->cur_pos % sqr + head->x[2] >= sqr - 1)
		return (0);
	else
		i = -1;
		*result[head->cur_pos] = head->symbol;
		while (++i < 3)
		{
			loc = head->cur_pos + head->x[i] + head->y[i] * sqr;
			if (*result[loc] == O_CHAR)
				*result[loc] = head->symbol;
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
		while (!place_element(head, sqr, result) && head->cur_pos < sqr * sqr)
			head->cur_pos++;
		if (head->cur_pos == sqr * sqr - 1)
			{
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

char	*solver(t_list *head)
{
	char	*result;
	int		sqr;

	sqr = 2;
	result = ft_strnew(sqr * sqr);
	ft_memset(&result, O_CHAR, sqr * sqr);
	while (!solve(head, &result, sqr))
	{
		ft_strdel(&result);
		sqr++;
		result = ft_strnew(sqr * sqr);
		ft_memset(&result, O_CHAR, sqr * sqr);
	}
	ft_lstdel(&head);
	return (result);
}
