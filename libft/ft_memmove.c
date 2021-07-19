/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:51:12 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/20 20:17:57 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	e;

	e = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	if (dst > src)
	{
		while (len > e)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		while (e < len)
		{
			((char *)dst)[e] = ((char *)src)[e];
			e++;
		}
	}
	return (dst);
}
