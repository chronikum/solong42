/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:58:31 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/05 10:39:29 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numberlength(int n)
{
	int	o;
	int	l;

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

void	ft_complete_string(char *str, int neg, int n)
{
	if (neg == 1)
		str[0] = '-';
	str[ft_numberlength(n) + neg] = '\0';
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		length;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	length = ft_numberlength(n);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	str = (char *)malloc((sizeof(char) * ft_numberlength(n)) + 1 + neg);
	if (!str)
		return (0);
	ft_complete_string(str, neg, n);
	while (length--)
	{
		str[length + neg] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
