/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:51:32 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/23 09:24:16 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*g;
	int		t;

	i = 0;
	t = 0;
	while (s[t] != '\0')
		t++;
	t++;
	while (t != i)
	{
		if ((s[i] != c))
			i++;
		else
		{
			g = (char *) &s[i];
			return (g);
		}
	}
	return (0);
}
