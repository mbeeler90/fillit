/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeeler <mbeeler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/01/17 13:00:22 by mbeeler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_structure(t_list **head)
{
	
}

void	create_structure(t_list **head, int *position)
{
	t_list	*tmp;

	if (!*head)
		*head = create_element(position);
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = ->next;
		
	}
}