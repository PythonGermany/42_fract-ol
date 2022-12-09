/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:46:59 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/18 15:24:52 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s1[i])
		i++;
	ptr = (char *)malloc(i + 1);
	if (ptr)
	{
		while (i >= 0)
		{
			ptr[i] = s1[i];
			i--;
		}
	}
	return (ptr);
}
