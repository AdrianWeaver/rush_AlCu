/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:08 by aweaver           #+#    #+#             */
/*   Updated: 2022/02/12 16:00:29 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str_joined;

	str_joined = malloc(sizeof(*str_joined) * (ft_strlen_int(s1)
				+ ft_strlen_int(s2) + 1));
	if (str_joined == 0)
		return (0);
	str_joined[0] = 0;
	ft_strcat(str_joined, s1);
	free(s1);
	ft_strcat(str_joined, s2);
	return (str_joined);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c >= 256)
		c %= 256;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == c)
		return (&s[i]);
	return (0);
}
