/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:15:45 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/18 20:37:36 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static void	print_param2(char c, va_list ap, int *len, char *flags)
{
	int	nbr;

	if (c == 'x')
	{
		nbr = va_arg(ap, int);
		if (nbr && ft_strchr((const char *)flags, '#'))
			*len += ft_printf_str("0x");
		ft_putnbru(nbr, "0123456789abcdef", len);
	}
	else if (c == 'X')
	{
		nbr = va_arg(ap, int);
		if (nbr && ft_strchr((const char *)flags, '#'))
			*len += ft_printf_str("0X");
		ft_putnbru(nbr, "0123456789ABCDEF", len);
	}
	else
	{
		*len += ft_printf_char('%');
		*len += ft_printf_char(c);
	}
}

static void	print_param(char c, va_list ap, int *len, char *flags)
{
	int	nbr;

	if (c == 'c')
		*len += ft_printf_char(va_arg(ap, int));
	else if (c == 's')
		*len += ft_printf_str((char *)va_arg(ap, char *));
	else if (c == 'p')
		*len += ft_printf_ptr(va_arg(ap, void *));
	else if (c == 'i' || c == 'd')
	{
		nbr = va_arg(ap, int);
		if (nbr >= 0 && ft_strchr((const char *)flags, '+'))
			*len += ft_printf_char('+');
		else if (nbr >= 0 && ft_strchr((const char *)flags, ' '))
			*len += ft_printf_char(' ');
		ft_putnbrl(nbr, "0123456789", len);
	}
	else if (c == 'u')
		ft_putnbrul(va_arg(ap, unsigned int), "0123456789", len);
	else if (c == '%')
		*len += ft_printf_char('%');
	else
		print_param2(c, ap, len, flags);
}

static int	ft_vfprintf(const char *format, va_list ap)
{
	int		i;
	int		len;
	char	*flags;

	i = 0;
	len = 0;
	flags = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i += ft_printf_flags((char *)&format[i], &flags);
			print_param(format[i], ap, &len, flags);
			free(flags);
		}
		else
			len += ft_printf_char(format[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start (args, format);
	len = ft_vfprintf(format, args);
	va_end(args);
	return (len);
}
