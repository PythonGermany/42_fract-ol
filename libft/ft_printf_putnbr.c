/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:34:12 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/20 19:34:12 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_putnbrl(long int n, char *base, int *ln)
{
	long int	i;
	int			len;

	len = base_len(base);
	i = n % len;
	if (n < 0)
	{
		write(1, &"-", 1);
		(*ln)++;
		i = -(n % -len);
		if (n / len < 0)
			ft_putnbrl(-(n / len), base, ln);
	}
	if (n / len > 0)
		ft_putnbrl(n / len, base, ln);
	write(1, &base[i], 1);
	(*ln)++;
}

void	ft_putnbrul(unsigned long int n, char *base, int *ln)
{
	long unsigned int	i;
	int					len;

	len = base_len(base);
	i = n % len;
	if (n / len > 0)
		ft_putnbrul(n / len, base, ln);
	write(1, &base[i], 1);
	(*ln)++;
}

void	ft_putnbru(unsigned int n, char *base, int *ln)
{
	long unsigned int	i;
	int					len;

	len = base_len(base);
	i = n % len;
	if (n / len > 0)
		ft_putnbru(n / len, base, ln);
	write(1, &base[i], 1);
	(*ln)++;
}
