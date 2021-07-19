/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:57:54 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/19 16:34:58 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	c;

	c = 0;
	d = (char *) malloc(sizeof(char) * (len + 1));
	if (!d || !s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (d);
	while (c < len)
	{
		d[c] = s[c + start];
		c++;
	}
	d[c] = '\0';
	return (d);
}
