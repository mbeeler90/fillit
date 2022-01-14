/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/01/14 21:48:35 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_result(char *result)
{
	int	sqr;
	int len;
	int	i;

	len = ft_strlen(result);
	sqr = 0;
	while (sqr * sqr < len)
		sqr++;
	i = -1;
	while (++i != len)
	{
		ft_putchar(result[i]);
		if ((i + 1) % sqr == 0)
			ft_putchar('\n');
	}
}