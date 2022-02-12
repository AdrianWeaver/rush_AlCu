/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alcu_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:42:39 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 20:52:52 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alcu.h"
#include "get_next_line.h"
#include "stdlib.h"

static int	ft_check_alcu_map(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	while (*str == 0)
		str++;
	if (ft_strlen(str) > 5 || ft_atoi(str) > 1000)
		return (-1);
	return (0);
}

int	ft_check_heap(t_map *map)
{
	if (map->heap[0] == 0)
		return (-1);
	return (0);
}

int	alcu_parsing(int fd, t_map *map)
{
	char	*str;
	int		i;

	i = 0;
	map->size = 0;
	map->heap = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (ft_check_alcu_map(str) == -1)
		{
			free(str);
			if (i > 0)
				free(map->heap);
			return (-1);
		}
		map->heap = ft_realloc(map->heap, (i * sizeof(*map->heap)),
				((i + 1) * sizeof(*map->heap)));
		if (map->heap == 0)
			return (-1);
		map->heap[i] = ft_atoi(str);
		map->size++;
		free(str);
		i++;
	}
	return (ft_check_heap(map));
}
