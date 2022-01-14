/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/01/14 13:20:42 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int shape_recognition(char *shape)
{
	int	i;
	char *temp;

	temp = strchr(shape, '#');
	if (temp == 0)
	{
		ft_putstr_fd(2, "invalid file");
		return (-1);
	}
	
	
}

static void	readfile(char **argv)
{
	int		fd;
	int		readed;
	char	buff[BUFF_SIZE + 1];

	readed = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1)
	while (readed > 0)
	{
		readed = read(fd, buff, BUFF_SIZE);
		if (readed < 0)
			return (-1);
		if ((shape_recognition(buff)) == -1);
			return (-1);
	}
	return()
}

int main(int argc, char **argv)
{
	if (agrc != 2)
	{
		ft_putstr_fd(2, USAGE);
		return (-1);
	}
	readfile(argv)
}