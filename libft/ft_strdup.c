/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:15:21 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/18 15:48:20 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (dest[i] == '\0')
			return (dest);
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc(ft_strlen((char *)s1) + 1);
	if (dest != 0)
	{
		ft_strcpy((char *) dest, (char *) s1);
		return (dest);
	}
	return (0);
}
