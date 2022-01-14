/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/01/14 23:10:07 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //

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

	//printf("char: %s\n", *result);
	//printf("cur_pos: %d\n", head->cur_pos);
	//printf("combined: %c\n", *(*result + head->cur_pos));
	if (*(*result + head->cur_pos) != O_CHAR)
	{
		//printf("should be none\n");
		return (0);
	}
	else if (head->cur_pos / sqr + head->y[2] >= sqr)
	{
		//printf("exceeds vertically\n");
		return (0);
	}
	else if (head->cur_pos % sqr + head->x[2] >= sqr)
	{
		//printf("exceeds horicontally");
		return (0);
	}
	else
	{
	//	printf("result in else: %s\n", *result);
		i = -1;
		*(*result + head->cur_pos) = head->symbol;
		while (++i < 3)
		{
			loc = head->cur_pos + head->x[i] + head->y[i] * sqr;
			if (*(*result + loc) == O_CHAR)
				*(*result + loc) = head->symbol;
			else
			{
				clear_result(result, head->symbol);
				return (0);
			}
		}
		return (1);
	}
}

static int	solve(t_list *head, char **result, int sqr)
{
	int	solution;

	while (head)
	{
		solution = 1;
	//	printf("%d -> #solution\n", solution);
		while (head->cur_pos < sqr * sqr && place_element(head, sqr, result) == 0)
		{
	//		printf("new head, cur_head: %d\n", head->cur_pos);
			head->cur_pos++;
		}
		if (head->cur_pos == sqr * sqr)
		{
	//		printf("no valid solution found\n");
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
//	printf("%d -> solution\n", solution);
	return (solution);
}

char	*solver(t_list *head)
{
	char	*result;
	int		sqr;

	sqr = 2;
	result = ft_strnew(sqr * sqr);
	result = ft_memset(result, O_CHAR, sqr * sqr);
	while (solve(head, &result, sqr) == 0)
	{
		ft_strdel(&result);
		sqr++;
		result = ft_strnew(sqr * sqr);
		result = ft_memset(result, O_CHAR, sqr * sqr);
	//	printf("result:\n%s\n", result);
	}
	//ft_lstdel(&head);
	return (result);
}
