/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:04:16 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/19 11:50:38 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if ((!dst && !src) || ((!dst || !src) && !n))
		return (dst);
	while (n > 0)
	{
		n--;
		*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	}
	return (dst);
}
