/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:52:13 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/12 16:10:45 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/alcu.h"

void	ft_init(t_map *map)
{
	int	i;

	map->rest = ft_calloc(map->size + 1, sizeof(int));
	map->rest[0] = 1;
	i = 0;
	while (i < map->size)
	{
		if ((map->heap[i] - map->rest[i]) % 4)
			map->rest[i + 1] = 1;
		i++;
	}
}

int	ft_ia_turn(t_map *map)
{
	int	i;
	int	result;

	i = map->size - 1;
	result = (map->heap[i] - map->rest[i]) % 4;
	if (result == 0)
		return (0);
	return (result);
}

int	ft_player_turn(void)
{
	return (1);
}

void	ft_play(t_map *map, int move)
{
	map->heap[map->size - 1] -= move;
	if (map->heap[map->size - 1] == 0)
		map->size--;
}

void	ft_game_loop(t_map *map)
{
	int	player;
	int	move;

	player = 0;
	ft_init(map);
	while (map->heap[0])
	{
		ft_display_board(map);
		move = 0;
		if (player)
		{
			move = ft_player_turn();
			player = 0;
		}
		else
		{
			move = ft_ia_turn(map);
			player = 1;
		}
		ft_play(map, move);
	}
}
