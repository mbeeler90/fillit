/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:54:28 by jjuntune          #+#    #+#             */
/*   Updated: 2022/01/14 20:40:28 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

# define BUFF_SIZE 21
# define S_CHAR '#' 
# define O_CHAR '.'
# define START_C 'A'

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			symbol;
	int				cur_pos;
	int				x[3];
	int				y[3];
}					t_list;

char	*solver(t_list *head);

#endif
