/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:54:29 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/16 00:54:29 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			t = *lst;
			while (t->next)
				t = t->next;
			t->next = new;
		}
	}
}
