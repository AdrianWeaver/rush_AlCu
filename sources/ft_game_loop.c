/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:52:13 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/12 22:32:40 by bregneau         ###   ########.fr       */
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

int	ft_check_move(t_map *map, char* str)
{
	int	move;
	
	if (ft_strlen(str) != 1 || ((*str != '1') || (*str != '2')
		|| (*str != '3')) || ft_atoi(str) > map->heap[map->size - 1])
	{
		ft_putstr_no_nl(str);
		ft_putstr(" - Invalid choice\n");
		return (-1);
	}
	move = ft_atoi(str);
	free(str);
	return (move);
}

int	ft_player_turn(t_map *map, int fake_stdin)
{
	char	*line;
	int		move;

	ft_putendl("Please choose between 1 and 3 items");
	line = get_next_line(fake_stdin);
	do
	{
		move = ft_check_move(map, line);
	} while (move != -1);
	return (ft_atoi(line));
}

void	ft_play(t_map *map, int move)
{
	map->heap[map->size - 1] -= move;
	if (map->heap[map->size - 1] == 0)
		map->size--;
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
			ft_player_turn(map, fake_stdin);
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
