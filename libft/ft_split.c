/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:34:32 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/15 10:34:32 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	countwords(char const *s, char c, int *i)
{
	int	count;

	count = 0;
	*i = 0;
	while (s[*i])
	{
		if (s[*i] != c && (s[*i + 1] == c || !s[*i + 1]))
			count++;
		(*i)++;
	}
	return (count);
}

static void	*free_all(char **arr, int start, int stop)
{
	while (start <= stop)
		free(arr[start++]);
	free(arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		count;
	char	**out;

	if (!s)
		return (0);
	count = countwords(s, c, &i);
	out = (char **)malloc((count + 1) * sizeof(char *));
	if (!out)
		return (0);
	out[count] = 0;
	while (count > 0)
	{
		len = 0;
		while (!(s[i - 1] != c && (s[i] == c || !s[i])) && i > 0)
			i--;
		while (i - len > 0 && s[i - len - 1] != c)
			len++;
		out[--count] = ft_substr(s, i - len, len);
		if (!out)
			return (free_all(out, count, countwords(s, c, &i)));
		i -= len;
	}
	return (out);
}
