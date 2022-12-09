/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:17:22 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/15 20:17:22 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*out;

	len = get_len(n);
	out = (char *)malloc(len + 1);
	if (out)
	{
		if (n == 0)
			out[0] = '0';
		out[len] = 0;
		if (n < 0)
			out[0] = '-';
		while (n / 10 != n)
		{
			if (n < 0)
				out[--len] = -(n % -10) + '0';
			else
				out[--len] = n % 10 + '0';
			n /= 10;
		}
	}
	return (out);
}
