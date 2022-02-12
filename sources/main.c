/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:39:03 by aweaver           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/02/12 19:15:19 by aweaver          ###   ########.fr       */
=======
/*   Updated: 2022/02/12 18:44:36 by bregneau         ###   ########.fr       */
>>>>>>> a29a2f591f99362aeaa6f72fade605851f9f82df
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
<<<<<<< HEAD
#include "libftprintf.h"
#include "fcntl.h"
#include <stddef.h>
=======
>>>>>>> a29a2f591f99362aeaa6f72fade605851f9f82df

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
