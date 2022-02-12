/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alcu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:52:13 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/12 20:09:27 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

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
	int	move;

	i = map->size - 1;
	move = (map->heap[i] - map->rest[i]) % 4;
	if (move == 0)
		move = 1;
	ft_printf("IA took %d\n", move);
	return (move);
}

int	ft_player_turn(void)
{
	char	*line;
	line = get_next_line(0);
	return (ft_atoi(line));
}

void	ft_play(t_map *map, int move)
{
	map->heap[map->size - 1] -= move;
	if (map->heap[map->size - 1] == 0)
		map->size--;
}

int	ft_check_move(t_map *map, int move)
{
	if ((move < 1) || (move > 3) || move > map->heap[map->size - 1])
	{
		ft_printf("%d - Invalid choice\n", move);
		return (0);
	}
	return (1);
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
		if (player)
		{
			ft_printf("AI 2\n");
			move = ft_ia_turn(map);
			// do
			// {
			// 	move = ft_player_turn();
			// } while (ft_check_move(map, move));
			
			player = 0;
		}
		else
		{
			ft_printf("AI 1\n");
			move = ft_ia_turn(map);
			player = 1;
		}
		ft_play(map, move);
	}
}
