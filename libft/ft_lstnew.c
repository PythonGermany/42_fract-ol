/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:04:39 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/16 00:04:39 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*el;

	el = (t_list *)malloc(sizeof(t_list));
	if (el)
	{
		el->content = content;
		el->next = 0;
	}
	return (el);
}
