/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:37:32 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/19 14:13:11 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!dstsize)
	{
		while (src[i2])
			i2++;
		return (i2);
	}
	while (dst[i] && i < dstsize)
		i++;
	while (dstsize > 1 && i + i2 < dstsize - 1 && src[i2])
	{
		dst[i + i2] = src[i2];
		i2++;
	}
	if (dstsize > 0 && i < dstsize)
		dst[i + i2] = 0;
	while (src[i2])
		i2++;
	return (i + i2);
}
