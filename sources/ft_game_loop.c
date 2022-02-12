/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:52:13 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/12 22:01:21 by bregneau         ###   ########.fr       */
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
	ft_putstr("IA took ");
	ft_putnbr(move);
	ft_putstr(" \n");
	return (move);
}

int	ft_player_turn(int fake_stdin)
{
	char	*line;

	ft_putendl("Please choose between 1 and 3 items");
	line = get_next_line(fake_stdin);
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
		ft_putnbr(move);
		ft_putstr(" - Invalid choice\n");
		return (0);
	}
	return (1);
}

void	ft_game_loop(t_map *map, int fake_stdin)
{
	int	player;
	int	move;

	(void)fake_stdin;
	player = 0;
	ft_init(map);
	while (map->heap[0])
	{
		ft_display_board(map);
		if (player)
		{
			do
			{
				move = ft_player_turn(fake_stdin);
			} while (ft_check_move(map, move) == 0);
			
			player = 0;
		}
		else
		{
			move = ft_ia_turn(map);
			player = 1;
		}
		ft_play(map, move);
	}
	if (player)
		ft_putendl("You are the winner! Congratulations!");
	else
		ft_putendl("You lose !");
}
