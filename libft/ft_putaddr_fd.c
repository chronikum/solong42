/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:59:01 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/19 08:33:19 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddr_fd(void *p)
{
	int		l;

	l = 0;
	if (!p)
		return (ft_putstr("0x0"));
	l += ft_putstr("0x");
	l += ft_dec_to_hex((unsigned long long) p, 1, 1);
	return (l);
}
