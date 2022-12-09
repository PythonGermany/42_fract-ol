/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:31:16 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/28 23:35:14 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && i < start)
		i++;
	if (i < start)
		return ((char *)ft_calloc(1, 1));
	while (s[i] && i < start + len)
		i++;
	dest = (char *)malloc(i - start + 1);
	if (!dest)
		return (0);
	dest[i - start] = 0;
	while (i > start)
	{
		i--;
		dest[i - start] = s[i];
	}
	return (dest);
}
