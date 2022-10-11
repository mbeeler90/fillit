/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/10/11 15:50:19 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Print the result by creating a string in the size of the result. Go through
** the linked list and add the output to the sring in the right place.
*/
void	print_result(t_list *head, int sqr)
{
	int		i;
	int		pos;
	char	*result;

	result = ft_strnew(sqr * sqr);
	ft_memset(result, '.', sqr * sqr);
	while (head)
	{
		i = -1;
		while (++i < EL_SIZE)
		{
			pos = head->cur_pos + head->position[i] % (EL_SIZE + 1)
				+ sqr * (head->position[i] / (EL_SIZE + 1));
			result[pos] = head->symbol;
		}
		head = head->next;
	}
	i = -1;
	while (++i < sqr * sqr)
	{
		ft_putchar(result[i]);
		if ((i + 1) % sqr == 0)
			ft_putchar('\n');
	}
	ft_strdel(&result);
}
