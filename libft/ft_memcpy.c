/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:41:00 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/18 15:46:00 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	e;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == 0 && src == 0)
		return (0);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	e = 0;
	while (n > e)
	{
		d[e] = s[e];
		e++;
	}
	return (dst);
}
