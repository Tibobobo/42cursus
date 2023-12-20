/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:52:22 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/14 11:13:35 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;
	t_list	*next_element;

	element = *lst;
	while (element != NULL)
	{
		next_element = element->next;
		(*del)(element->content);
		free(element);
		element = next_element;
	}
	*lst = NULL;
}
