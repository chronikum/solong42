/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunlonglong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:04:12 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/05 13:38:19 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_biggest_unsigned(unsigned long long int n, int fd)
{
	if (n == 9223372036854775807)
	{
		ft_putstr_fd("9223372036854775807", fd);
		return (1);
	}
	return (0);
}

void	ft_putunlonglong(unsigned long long n, int fd)
{
	unsigned long long int	t;
	char					c;

	t = 0;
	c = n + 48;
	if (!ft_check_biggest_unsigned(n, fd))
	{
		if (n > 9)
		{
			t = n % 10;
			n /= 10;
			c = t + 48;
			ft_putunlonglong(n, fd);
		}
		else
		{
			c = n + 48;
		}
		write(fd, &c, 1);
	}
}
