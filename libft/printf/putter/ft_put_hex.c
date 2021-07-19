/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:44:40 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/19 08:34:07 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_put_hex(unsigned long long p, int u)
{
	if (p == 0)
		return (ft_putstr("0"));
	if (u == 1)
		return (ft_dec_to_hex(p, 0, 1));
	return (ft_dec_to_hex(p, 1, 1));
}
