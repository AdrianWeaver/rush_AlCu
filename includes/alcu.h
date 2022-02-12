/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:37:23 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/12 20:16:01 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "libft.h"
# include "unistd.h"
# include "alcu.h"
# include "libftprintf.h"
# include "get_next_line.h"
# include "stdlib.h"
# include "fcntl.h"

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

int		alcu_parsing(int fd, t_map *map);

# endif

# ifndef FT_DISPLAY_BOARD
#  define FT_DISPLAY_BOARD

void	ft_display_board(t_map *map);

# endif

# ifndef FT_GAME_LOOP
#  define FT_GAME_LOOP

void	ft_game_loop(t_map *map, int fake_stdin);

# endif
#endif
