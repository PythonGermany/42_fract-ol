/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:44:41 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/15 11:44:41 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*out;

	i = 0;
	if (!s || !f)
		return (0);
	while (s[i])
		i++;
	out = (char *)malloc(i + 1);
	if (!out)
		return (0);
	out[i] = 0;
	while (i > 0)
	{
		i--;
		out[i] = (*f)(i, s[i]);
	}
	return (out);
}
