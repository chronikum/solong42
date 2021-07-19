/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:42:03 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/18 15:08:18 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	t;
	size_t	j;
	size_t	i;
	size_t	s;

	t = ft_strlen((const char *)dst);
	j = t;
	i = 0;
	s = ft_strlen(src);
	while ((t < dstsize) && (src[i] != '\0') && (j < dstsize - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	if (dstsize != 0 && (t < dstsize))
		dst[j] = '\0';
	if (t > dstsize)
		return (dstsize + s);
	return (t + s);
}
