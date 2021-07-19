/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:35:39 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/19 08:36:10 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_numberlength(unsigned int n)
{
	unsigned int	o;
	unsigned int	l;

	o = n;
	l = 0;
	if (n < 0)
		o = -o;
	while (o > 0)
	{
		o /= 10;
		l++;
	}
	return (l);
}

int	ft_putuint(unsigned int n)
{
	ft_putunbr_fd(n, 1);
	if (n == 0)
		return (1);
	return (ft_numberlength(n));
}
