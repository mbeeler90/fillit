/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeeler <mbeeler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/01/17 13:04:27 by mbeeler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	validate_lines(char *buff, int **position)
{
	int i;
	int	count;

	i = -1;
	count = 0;
	while (++i < BUFF_SIZE)
	{
		if (i == 20 && buff[i] != '\n' && buff[i] != '\0')
			return (0);
		else if (i % (EL_SIZE + 1) == EL_SIZE && buff[i] != '\n')
			return (0);
		else
		{
			if (buff[i] != S_CHAR && buff[i] != O_CHAR)
				return (0);
			else if (buff[i] == S_CHAR)
			{
				*position[count] = i;
				count++;			
			}
		}
	}
	if (count != 4)
		return (0);
	return (1);
}

static int	check_count(int *count)
{
	int	sum;
	int	i;

	sum = 0;
	i = -1;
	while (++i < EL_SIZE)
	{
		if (count[i] == 2)
			sum++;
		else if (count[i] == 3)
			sum += 2;
	}
	if (sum >= 2)
		return (1);
	else
		return (0);
}

static int	validate_shape(int *position)
{
	int	i;
	int	j;
	int	count[4];

	i = -1;
	while (++i < EL_SIZE)
	{
		count[i] = 0;
		j = -1;
		while (++j < EL_SIZE)
		{
			if (position[i] - (EL_SIZE + 1) == position[j])
				count[i]++;
			if (position[i] - 1 == position[j])
				count[i]++;
			if (position[i] + 1 == position[j])
				count[i]++;
			if (position[i] + (EL_SIZE + 1) == position[j]) 
				count[i]++;
		}
	}
	return (check_count(count));
}

t_list	*read_file(char **argv, int *lstlen)
{
	int		fd;
	int		f_read;
	int		*position[4];
	char	buff[BUFF_SIZE + 1];
	t_list	*head;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, buff, 0) == -1)
		return (-1);
	f_read = 1;
	head = NULL;
	while (f_read > 0)
	{
		f_read = read(fd, buff, BUFF_SIZE);
		buff[f_read] = '\0';
		if (!validate_lines(buff, &position) || !validate_shape(position))
		{
			delete_structure(&head);
			return (NULL);
		}
		create_structure(&head, position);
	}
	return(head);
}
