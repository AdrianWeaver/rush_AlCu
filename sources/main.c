/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:33:26 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/13 18:33:28 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libftprintf.h"
#include "fcntl.h"
#include <stddef.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		fake_stdin;
	t_map	map;

	fake_stdin = 0;
	if (argc == 1)
	{
		if (alcu_parsing(0, &map) == -1)
		{
			ft_putstr("ERROR\n");
			return (-1);
		}
	}
	if (argc > 2)
	{
		ft_putstr("ERROR\n");
		return (-1);
	}
	if (argc != 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("ERROR\n");
			return (-1);
		}
		if (alcu_parsing(fd, &map) == -1)
		{
			ft_putstr("ERROR\n");
			return (-1);
		}
	}
	close(0);
	fake_stdin = open("/dev/tty", O_RDONLY);
	ft_game_loop(&map, fake_stdin);
	free(map.heap);
	return (0);
}
