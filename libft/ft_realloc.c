/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:34:30 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/22 19:41:13 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t size)
{
	void	*dst;
	dst = malloc(size);
	if (!dst)
	{
		free(src);
		return (NULL);
	}
	if (!src)
		return (NULL);
	ft_memmove(dst, src, size);
	free(src);
	return (dst);
}