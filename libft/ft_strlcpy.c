/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:25:04 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/23 12:15:16 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	l;

	if (dst == 0 || src == 0)
		return (0);
	l = 0;
	c = 0;
	while (src[l] != '\0')
		l++;
	while (src[c] && c < (dstsize - 1))
	{
		if (dstsize == 0)
			return (l);
		dst[c] = src[c];
		c++;
	}
	if (dstsize != 0)
		dst[(c)] = '\0';
	return (l);
}
