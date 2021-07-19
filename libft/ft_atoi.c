/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:13:18 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/20 19:54:02 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c);

int	whitespace(char c)
{
	return ((c == '\t') || (c == '\n')
		|| (c == '\v') || (c == '\f') || (c == '\r') || (c == ' '));
}

int	ft_skip_plus_minus(const char *str, int p, int *m)
{
	int	a;

	a = 0;
	if (str[p] == '-' && ft_isdigit((int) str[p + 1]))
	{
		*m = -1;
		a++;
	}
	if (str[p] == '+' && ft_isdigit((int) str[p + 1]))
	{
		*m = 1;
		a++;
	}
	if (ft_isdigit((int) str[p]))
		*m = 1;
	return (p + a);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		r;
	int		m;

	i = 0;
	r = 0;
	m = 0;
	while (whitespace(str[i]))
		i++;
	i = ft_skip_plus_minus(str, i, &m);
	if (m == 0)
		return (0);
	if (str[i] == '0')
		i++;
	while (ft_isdigit((int) str[i]) && (str[i] != '\0'))
	{
		r = ((10 * r) + (str[i] - 48));
		i++;
	}
	return (r * m);
}
