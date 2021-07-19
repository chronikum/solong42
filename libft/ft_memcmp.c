/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:47:09 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/18 16:01:25 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	int				f;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	f = 0;
	t1 = (unsigned char *) s1;
	t2 = (unsigned char *) s2;
	while (f == 0 && (i < n) && (n != 0))
	{
		if (t1[i] > t2[i])
			f = t1[i] - t2[i];
		else if (t1[i] < t2[i])
			f = t1[i] - t2[i];
		i++;
	}
	return (f);
}
