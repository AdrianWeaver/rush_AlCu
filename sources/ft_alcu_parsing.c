/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alcu_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:42:39 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 16:34:07 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alcu.h"
#include "get_next_line.h"
#include "stdlib.h"

int	alcu_parsing(int fd, t_map *map)
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
				free(map->heap);
			return (-1);
		}
		if (*str != '\n' && str != NULL)
		{
			map->heap = ft_realloc(map->heap, i, i + 1);
			if (map->heap == 0)
				return (-1);
			map->heap[i + 1] = 0;
			map->heap[i] = ft_atoi(str);	
			map->size++;
		}
		i++;
	} while (str); 
	return (0);		
}
