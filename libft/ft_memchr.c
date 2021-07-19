/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:25:48 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/13 13:44:06 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*g;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *) s;
	while (n > i)
	{
		if ((d[i] != (unsigned char)c))
			i++;
		else
		{
			g = (unsigned char *) &s[i];
			return (g);
		}
	}
	return (0);
}
