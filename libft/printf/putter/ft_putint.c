/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:26:08 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/19 08:26:45 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_numberlength(int n)
{
	unsigned int	o;
	int				l;

	l = 0;
	if (n < 0)
	{
		o = -n;
	}
	else
	{
		o = n;
	}
	while (o > 0)
	{
		o /= 10;
		l++;
	}
	return (l);
}

int	ft_putint(int n)
{
	ft_putnbr_fd(n, 1);
	if (n == 0)
		return (1);
	if (n < 0)
		return (ft_numberlength(n) + 1);
	return (ft_numberlength(n));
}
