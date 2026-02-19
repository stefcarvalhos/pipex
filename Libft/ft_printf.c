/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:38:11 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/22 13:38:11 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	ft_print_format(const char *format, int i, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			count = count + ft_print_format(format, i, args);
			i++;
		}
		else
		{
			count = count + ft_print_c(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

static	int	ft_print_format(const char *format, int i, va_list args)
{
	if (format[i + 1] == '%')
		return (ft_print_c('%'));
	else if (format[i + 1] == 'c')
		return (ft_print_c((char)va_arg(args, int)));
	else if (format[i + 1] == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_print_di(va_arg(args, int)));
	else if (format[i + 1] == 'u')
		return (ft_print_u(va_arg(args, unsigned int)));
	else if (format[i + 1] == 'x')
		return (ft_print_x(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format[i + 1] == 'X')
		return (ft_print_x(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format[i + 1] == 'p')
		return (ft_print_p(va_arg(args, void *), "0123456789abcdef"));
	return (0);
}
