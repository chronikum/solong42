/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:11:26 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/18 15:57:25 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				f;

	i = 0;
	f = 0;
	while (f == 0 && (i < n) && (n != 0))
	{
		if ((unsigned char) s1[i] == '\0'
			&& (unsigned char) s2[i] == '\0')
			return (f);
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			f = 1;
		else if ((unsigned char) s1[i] < (unsigned char) s2[i])
			f = -1;
		i++;
	}
	return (f);
}
