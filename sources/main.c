/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:43:49 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 17:50:07 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include "alcu.h"
#include "libftprintf.h"
#include "fcntl.h"

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
	free(map.heap);
	return (0);
}
