/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/19 08:57:12 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_handle_percent(int *p)
{
	(*p)++;
	if (*p % 2 == 0)
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

static int	ft_check_type(char format, va_list args)
{
	int	l;

	l = 0;
	if (format == 'd' || format == 'i')
		l += ft_putint(va_arg(args, int));
	if (format == 'c')
		l += ft_putchar((char) va_arg(args, int));
	if (format == 's')
		l += ft_putstr(va_arg(args, char *));
	if (format == 'u')
		l += ft_putuint(va_arg(args, unsigned int));
	if (format == 'p')
		l += ft_putaddr_fd(va_arg(args, void *));
	if (format == 'x')
		l += ft_put_hex(va_arg(args, unsigned int), 0);
	if (format == 'X')
		l += ft_put_hex(va_arg(args, unsigned int), 1);
	return (l);
}

static int	ft_print_format(char *format, va_list args, int l)
{
	int	i;
	int	p;

	i = 0;
	p = 1;
	while (format[i])
	{
		if ((format[i - 1] == '%'
				&& format[i - 2] != '%') && ft_is_available_type(format[i]))
			l += ft_check_type(format[i], args);
		else if (format[i - 1] == '%' && format[i] == '%')
			l += ft_handle_percent(&p);
		else if (format[i] != '%')
			l += ft_putchar(format[i]);
		if (format[i + 1] != '%')
			p = 1;
		i++;
	}
	return (l);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		l;

	l = 0;
	va_start(args, format);
	l = ft_print_format((char *) format, args, l);
	va_end(args);
	return (l);
}
