/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:27:31 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/16 00:27:31 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*t;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			t = *lst;
			*lst = new;
			new->next = t;
		}
	}
}
