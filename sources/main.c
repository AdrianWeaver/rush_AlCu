/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:39:03 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 18:44:36 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc != 2)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	if (alcu_parsing(fd, &map) == -1)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	ft_game_loop(&map);
	ft_display_board(&map);
	free(map.heap);
	return (0);
}
