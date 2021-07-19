/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:56:50 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/18 15:52:44 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;

	p = malloc(count * size);
	if (p != 0)
	{
		ft_bzero(p, count * size);
		return (p);
	}
	return (0);
}
