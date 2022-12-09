/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:54:25 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/19 15:39:49 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hi;
	size_t	ni;
	size_t	nlen;

	hi = 0;
	nlen = 0;
	while (needle[nlen])
		nlen++;
	if (!nlen)
		return ((char *)haystack);
	if (!len)
		return (0);
	while (haystack[hi] && hi + nlen <= len)
	{
		ni = 0;
		while (haystack[hi + ni] == needle[ni] && ni < nlen)
			if (++ni == nlen)
				return ((char *)&haystack[hi]);
		hi++;
	}
	return (0);
}
