/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:43:50 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/13 19:46:13 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int	ft_check_max(t_map *map)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < map->size)
	{
		if (map->heap[i] > max)
			max = map->heap[i];
		i++;
	}
	return (max);
}

void	ft_display_board(t_map *map)
{
	int	max;
	int	i;	
	int	j;

	i = 0;
	max = ft_check_max(map);
	while (i < map->size && map->heap[i] != 0)
	{
		j = 0;
		while (j < max - map->heap[i])
		{
			ft_putchar(' ');
			j++;
		}
		j = 0;
		while (j < map->heap[i] && map->heap[i] > 0)
		{
			ft_putchar('|');
			if (j != (map->heap[i] - 1))
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
