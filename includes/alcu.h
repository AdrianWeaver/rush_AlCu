/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:37:23 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/12 17:44:34 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "libft.h"

# ifndef S_MAP
#  define S_MAP

typedef struct s_map
{
	int	*heap;
	int	*rest;
	int	size;
}	t_map;

# endif

# ifndef ALCU_PARSING
#  define ALCU_PARSING

int	alcu_parsing(int fd, t_map *map);

# endif

# ifndef FT_DISPLAY_BOARD
#  define FT_DISPLAY_BOARD

void	ft_display_board(t_map *map);

# endif

#endif
