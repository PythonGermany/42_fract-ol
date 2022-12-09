/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:28:15 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/25 16:53:04 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (((count == (size_t)-1 && size) || (size == (size_t)-1 && count)))
		return (0);
	ptr = malloc(count * size);
	if (ptr)
		while (i < count * size)
			*((unsigned char *)ptr + i++) = 0;
	return (ptr);
}
