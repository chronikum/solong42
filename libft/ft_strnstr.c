/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:58:18 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/23 13:03:18 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	l;

	h = 0;
	l = ft_strlen(needle);
	if (l == 0 || len == 0)
		return ((char *)(&haystack[0]));
	while (haystack[h])
	{
		if (ft_strncmp(&haystack[h], needle, ft_strlen(needle)) == 0)
		{
			if ((ft_strlen(needle) + h) > len)
				return ((void *)0);
			return ((char *)(&haystack[h]));
		}
		h++;
	}
	return ((void *)0);
}
