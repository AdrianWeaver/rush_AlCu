/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:39:03 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 19:15:19 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
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
		if (alcu_parsing(STDIN_FILENO, &map) == -1)
			return (-1);
	}
	if (argc > 2)
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
	close(STDIN_FILENO);
	fake_stdin = open("/dev/tty", O_RDONLY);
	ft_game_loop(&map, fake_stdin);
	ft_display_board(&map);
	free(map.heap);
	return (0);
}
