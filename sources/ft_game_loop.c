/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:52:13 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/13 00:41:07 by bregneau         ###   ########.fr       */
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
	ft_putstr("AI took ");
	ft_putnbr(move);
	ft_putstr(" \n");
	return (move);
}

int	ft_check_move(t_map *map, char* str)
{
	int	move;
	char *save;
	
	save = str;
	while (*str == '0')
		str++;
	move = ft_atoi(str);
	if (ft_strlen(str) != 2 || move < 1 || move > 3 || move > map->heap[map->size - 1])
	{
		ft_putstr_no_nl(save);
		ft_putstr(" - Invalid choice\n");
		return (0);
	}
	return (move);
}

int	ft_player_turn(t_map *map, int fake_stdin)
{
	char	*line;
	int		move;

	do
	{
		ft_putendl("Please choose between 1 and 3 items");
		line = get_next_line(fake_stdin);
		move = ft_check_move(map, line);
		free(line);
	} while (move == 0);
	return (move);
}

void	ft_play(t_map *map, int move)
{
	map->heap[map->size - 1] -= move;
	if (map->heap[map->size - 1] <= 0)
		map->size--;
}

void	ft_game_loop(t_map *map, int fake_stdin)
{
	int	player;
	int	move;

	player = 0;
	ft_init(map);
	while (map->heap[0] > 0)
	{
		ft_display_board(map);
		if (player)
		{
			move = ft_player_turn(map, fake_stdin);
			player = 0;
		}
		else 
		{
			move = ft_ia_turn(map);
			player = 1;
		}
		ft_play(map, move);
	}
	free(get_next_line(-1));
	free(map->rest);
	if (player)
		ft_putendl("You are the winner! Congratulations!");
	else
		ft_putendl("You lose !");
}
