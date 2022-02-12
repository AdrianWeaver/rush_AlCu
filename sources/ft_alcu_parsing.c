/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alcu_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:42:39 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 18:45:00 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int	alcu_parsing(int fd, t_map *map)
{
	char	*str;
	int		i;

	i = 0;
	map->size = 0;
	map->heap = NULL;
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
		if (str != NULL)
		{
			map->heap = ft_realloc(map->heap, (i * sizeof(*map->heap)), ((i + 1) * sizeof(*map->heap)));
			if (map->heap == 0)
				return (-1);
			map->heap[i] = ft_atoi(str);	
			map->size++;
		}
		free(str);
		i++;
	} while (str); 
	return (0);		
}
