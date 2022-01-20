/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/01/20 13:22:45 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_structure(t_list **head)
{
	t_list	*tmp;
	int		i;

	i = -1;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->symbol = 0;
		tmp->cur_pos = 0;
		while (++i < EL_SIZE)
		{
			tmp->x[i] = 0;
			tmp->y[i] = 0;
		}
		free(tmp);
		tmp = NULL;
	}
}

static void	get_arrays(int *position, int *coord_ptr)
{
	int	i;
	int	min_x;
	int	min_y;

	i = -1;
	min_x = EL_SIZE;
	min_y = EL_SIZE;
	while (++i < EL_SIZE)
	{
		*(coord_ptr + i + EL_SIZE) = position[i] / (EL_SIZE + 1);
		*(coord_ptr + i) = position[i] % (EL_SIZE + 1);
		if (*(coord_ptr + i) < min_x)
			min_x = *(coord_ptr + i);
		if (*(coord_ptr + i + EL_SIZE) < min_y)
			min_y = *(coord_ptr + i + EL_SIZE);
	}
	i = -1;
	while (++i < EL_SIZE)
	{
		*(coord_ptr + i) -= min_x;
		*(coord_ptr + i + EL_SIZE) -= min_y;
	}
}

static t_list	*create_element(int *position, int *lstlen)
{
	t_list	*elem;
	int		i;
	int		coord_array[2 * EL_SIZE];
	int		*coord_ptr;

	i = -1;
	coord_ptr = coord_array;
	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->prev = NULL;
	elem->symbol = START_C + *lstlen;
	elem->cur_pos = 0;
	get_arrays(position, coord_ptr);
	while (++i < EL_SIZE)
	{
		elem->x[i] = coord_array[i];
		elem->y[i] = coord_array[i + EL_SIZE];
	}
	*lstlen += 1;
	return (elem);
}

int	create_structure(t_list **head, int *position, int *lstlen)
{
	t_list	*tmp;
	t_list	*new;

	if (!*head)
	{
		*head = create_element(position, lstlen);
		if (!*head)
			return (0);
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		new = create_element(position, lstlen);
		if (!new)
			return (0);
		tmp->next = new;
		new->prev = tmp;
	}
	return (1);
}
