/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:12:55 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/18 14:58:22 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	c;
	unsigned char	*t;

	c = 0;
	t = (unsigned char *)s;
	while (n > c)
	{
		t[c] = 0;
		c++;
	}
}
