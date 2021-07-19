/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:51:46 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/13 09:58:28 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_toupper((int) str[i]) != (int) str[i])
			str[i] = (char) ft_toupper((int) str[i]);
		i++;
	}
	return (str);
}
