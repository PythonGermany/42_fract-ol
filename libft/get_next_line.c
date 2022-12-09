/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:34:16 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/24 22:34:16 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static void	ft_free(void **ptr, void *new_val)
{
	if (*ptr)
		free(*ptr);
	*ptr = new_val;
}

static int	ft_strlen_gnl(char *str, int line_break)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && (str[i] != '\n' || !line_break))
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_cpappend(char **dst, char *src, int line_break)
{
	int		i;
	char	*buf;

	i = ft_strlen_gnl(*dst, line_break) + ft_strlen_gnl(src, line_break);
	buf = (char *)ft_calloc(1, i + 1);
	if (buf)
	{
		while (i-- > ft_strlen_gnl(*dst, line_break))
			buf[i] = src[i - ft_strlen_gnl(*dst, line_break)];
		i = ft_strlen_gnl(*dst, line_break);
		while (i-- > 0)
			buf[i] = dst[0][i];
	}
	ft_free((void **)dst, buf);
	return (buf);
}

static int	split_data(char **line, char **src_data, char **dst_data)
{
	char	*buf;

	if (ft_strlen_gnl(*src_data, 0) == ft_strlen_gnl(*src_data, 1))
	{
		ft_cpappend(line, *src_data, 0);
		ft_free((void **)dst_data, 0);
		if (!*line || line[0][ft_strlen_gnl(*line, 0) - 1] == '\n')
			return (0);
		return (1);
	}
	buf = 0;
	if (ft_cpappend(line, *src_data, 1))
		if (!ft_cpappend(&buf, *src_data + ft_strlen_gnl(*src_data, 1), 0))
			ft_free((void **)line, 0);
	ft_free((void **)dst_data, buf);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	int			ret;
	char		*buffer;

	line = 0;
	if (stash[fd] && fd >= 0 && BUFFER_SIZE > 0)
		if (!split_data(&line, &stash[fd], &stash[fd]))
			return (line);
	if (!stash[fd] && fd >= 0 && BUFFER_SIZE > 0)
	{
		buffer = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		ret = read(fd, buffer, BUFFER_SIZE);
		while (buffer && ret > 0)
		{
			buffer[ret] = 0;
			if (!split_data(&line, &buffer, &stash[fd]))
				break ;
			ret = read(fd, buffer, BUFFER_SIZE);
		}
		if (ret == -1 || !buffer)
			ft_free((void **)&line, 0);
		ft_free((void **)&buffer, 0);
	}
	return (line);
}
