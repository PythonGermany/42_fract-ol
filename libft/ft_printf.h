/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:30:39 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/18 20:31:29 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf_char(char c);
int		ft_printf_str(char *str);
int		ft_printf_ptr(void *ptr);
int		ft_printf_flags(char *format, char **flags);
void	ft_putnbrl(long int n, char *base, int *ln);
void	ft_putnbrul(unsigned long int n, char *base, int *ln);
void	ft_putnbru(unsigned int n, char *base, int *ln);

#endif