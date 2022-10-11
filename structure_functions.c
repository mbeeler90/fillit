/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/10/11 15:39:50 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Delete the linked list and free the allocated memory.
*/
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
		tmp->code = 0;
		tmp->x = 0;
		tmp->y = 0;
		while (++i < EL_SIZE)
			tmp->position[i] = 0;
		free(tmp);
		tmp = NULL;
	}
}

/*
** Function to get the hight and width if a piece is placed in certain position
** to check whether the piece fits in the square or not.
*/
static void	get_heigth_and_width(t_list *elem, int *position)
{
	int	min_x;
	int	min_y;
	int	i;

	i = -1;
	min_x = *position % (EL_SIZE + 1);
	min_y = *position / (EL_SIZE + 1);
	while (++i < EL_SIZE)
	{
		if (*(position + i) % (EL_SIZE + 1) < min_x)
			min_x = *(position + i) % (EL_SIZE + 1);
	}
	i = -1;
	elem->height = 0;
	elem->width = 0;
	while (++i < EL_SIZE)
	{
		*(position + i) -= (EL_SIZE + 1) * min_y + min_x;
		if (*(position + i) / (EL_SIZE + 1) > elem->height)
			elem->height = *(position + i) / (EL_SIZE + 1);
		if (*(position + i) % (EL_SIZE + 1) > elem->width)
			elem->width = *(position + i) % (EL_SIZE + 1);
	}
}

/*
** Each piece is decoded with a unique number to enable bitwise operations. 
** This function assignes a number to each piece.
*/
static void	get_code(t_list *elem, int *position)
{
	int						i;
	unsigned long long int	sum;

	i = -1;
	while (++i < EL_SIZE)
		*(position + i) += 15 - 2 * (*(position + i) % (EL_SIZE + 1))
			+ 11 * (*(position + i) / (EL_SIZE + 1));
	sum = 1;
	i = -1;
	elem->code = 0;
	while (++i < 64)
	{
		if (i == *(position))
			elem->code += sum;
		else if (i == *(position + 1))
			elem->code += sum;
		else if (i == *(position + 2))
			elem->code += sum;
		else if (i == *(position + 3))
			elem->code += sum;
		sum *= 2;
	}
}

/*
** Function to add a new piece to the linked list.
*/
static t_list	*create_element(int *position, int *lstlen)
{
	t_list	*elem;
	int		i;

	i = -1;
	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->prev = NULL;
	elem->symbol = START_C + *lstlen;
	elem->cur_pos = 0;
	elem->x = 0;
	elem->y = 0;
	get_heigth_and_width(elem, position);
	while (++i < EL_SIZE)
		elem->position[i] = position[i];
	get_code(elem, position);
	i = -1;
	*lstlen += 1;
	return (elem);
}

/*
** Function to create a linked list with the pieces, which have to be placed
** in a square.
*/
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
