/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:43:49 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 14:46:56 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

static int	alcu_parsing(int fd, t_map *map)
{
	char	*str;
	int		i;

	i = 0;
	map->size = 0;
	do
	{
		str = get_next_line(fd);
		if (ft_strlen(str) > 5 || ft_atoi(str) > 10000)
		{
			free(str);
			if (i > 0)
				free(heap);
			return (-1);
		}
		if (*str != '\n' && str != NULL)
		{
			heap = ft_realloc(heap, i, i + 1);
			if (heap == 0)
				return (-1);
			heap[i + 1] = 0;
			map->heap[i] = ft_atoi(str);	
			map->size++;
		}
	} while (str); 
	return (0);		
}

int	main(int argc, char **argv)
{
	int		b_read;
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
	return (0);
}

