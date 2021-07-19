/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:27:12 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/19 18:57:07 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	lenc;
	unsigned char	d;
	unsigned char	*t;

	lenc = 0;
	lenc = 0;
	d = (unsigned char)c;
	t = (unsigned char *)b;
	while (len > lenc)
	{
		t[lenc] = d;
		lenc++;
	}
	return (b);
}
