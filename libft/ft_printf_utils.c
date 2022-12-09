/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:57:12 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/18 20:26:30 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_str(char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	ft_putstr_fd("(null)", 1);
	return (6);
}

int	ft_printf_flags(char *format, char **flags)
{
	int		i;

	i = 0;
	while (ft_strchr("-0.# +", format[i]) && format[i])
		i++;
	*flags = ft_substr((char const *)format, 0, i);
	return (i);
}

int	ft_printf_ptr(void *ptr)
{
	int	len;

	len = 0;
	ft_putstr_fd("0x", 1);
	len += 2;
	ft_putnbrul((unsigned long int)ptr, "0123456789abcdef", &len);
	return (len);
}