/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:42:49 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/18 15:08:26 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*g;
	int		t;

	i = 0;
	t = 0;
	while (s[t] != '\0')
		t++;
	while (t != -1)
	{
		if ((s[t] != c))
			t--;
		else
		{
			g = (char *) &s[t];
			return (g);
		}
	}
	return (0);
}
