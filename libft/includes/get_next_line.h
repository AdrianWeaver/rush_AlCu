/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:50:34 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 15:57:29 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef FT_STRJOIN
#  define FT_STRJOIN

char	*ft_strjoin_free(char const *s1, char const *s2);

# endif
# ifndef FT_STRCHR_GNL
#  define FT_STRCHR_GNL

char	*ft_strchr_gnl(const char *s, int c);

# endif

# ifndef GET_NEXT_LINE
#  define GET_NEXT_LINE

char	*get_next_line(int fd);

# endif
#endif
