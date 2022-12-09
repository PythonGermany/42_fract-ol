/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 01:24:03 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/16 01:24:03 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*n;

	if (lst && del)
	{
		temp = *lst;
		if (temp)
		{
			del(temp->content);
			while (temp->next)
			{
				n = temp->next;
				free(temp);
				temp = n;
				del(temp->content);
			}
			free(temp);
		}
		*lst = 0;
	}
}
