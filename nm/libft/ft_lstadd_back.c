/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:51:54 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/11 09:45:13 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (*lst == NULL)
		*lst = new;
	else
	{
		element = *lst;
		while (element->next != NULL)
			element = element->next;
		element->next = new;
	}
}
