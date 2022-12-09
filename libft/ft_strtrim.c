/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:00:42 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/15 19:32:25 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	part_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (!s1 || !set)
		return (0);
	while (part_set(s1[i], set) && s1[i])
		i++;
	while (s1[i2])
		i2++;
	i2--;
	while (part_set(s1[i2], set) && i2 > i)
		i2--;
	return (ft_substr(s1, i, i2 - i + 1));
}
