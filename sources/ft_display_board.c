/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:43:50 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 13:36:02 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_max(t_map *data)
{
	int	max;

	max = 0;
	while (i < data->size)
	{
		if (data->heap[i] > max)
			max = data->heap[i];
		i++;
	}
	return (max);
}

void	ft_display_board(t_map *data)
{
	int	max;
	int	i;	
	int	j;

	i = 0;
	j = 0;
	max = ft_check_max(data);
	while (i < data->size)
	{
		while (j < (max - data->heap[i]) / 2)
		{
			ft_putchar(' ');
			j++;
		}
		j = 0;
		while (j < data->heap[i])
		{
			ft_putstr('|');
			if (j != (data->heap[i] - 1))
				ft_putstr(' ');
			j++;
		}
		while (j < (max - data->heap[i]) / 2)
			ft_putchar(' ');
		ft_putchar('\n');
		i++;
	}
}