/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:35:02 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/19 10:41:15 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*out;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i])
		i++;
	while (s2[i2])
		i2++;
	out = (char *)malloc(i + i2 + 1);
	if (out)
	{
		out[i + i2] = 0;
		while (i2-- > 0)
			out[i + i2] = s2[i2];
		while (i-- > 0)
			out[i] = s1[i];
	}
	return (out);
}
