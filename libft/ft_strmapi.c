/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:45:54 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/20 20:17:19 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*j;
	int		i;	

	i = 0;
	if (!s || !f)
		return (0);
	j = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!j)
		return (0);
	while (s[i] != '\0')
	{
		j[i] = f(i, s[i]);
		i++;
	}
	j[i] = '\0';
	return (j);
}
