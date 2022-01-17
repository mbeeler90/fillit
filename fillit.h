/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeeler <mbeeler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:54:28 by jjuntune          #+#    #+#             */
/*   Updated: 2022/01/17 10:26:54 by mbeeler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

# define S_CHAR '#' 
# define O_CHAR '.'
# define START_C 'A'
# define EL_SIZE 4
# define BUFF_SIZE EL_SIZE * (EL_SIZE + 1) + 1

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			symbol;
	int				cur_pos;
	int				x[EL_SIZE];
	int				y[EL_SIZE];
}					t_list;

t_list	*read_file(char **argv, int *lstlen);
char	*solver(t_list *head, int min_size);
void	print_result(char *result);

#endif
