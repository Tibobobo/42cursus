/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:52:49 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/14 11:15:13 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*res_begin;

	if (!lst)
		return (NULL);
	res_begin = ft_lstnew((*f)(lst->content));
	if (!res_begin)
		return (NULL);
	res = res_begin;
	lst = lst->next;
	while (lst != NULL)
	{
		res->next = ft_lstnew((*f)(lst->content));
		if (!res->next)
		{
			ft_lstclear(&res_begin, del);
			return (NULL);
		}
		res = res->next;
		lst = lst->next;
	}
	return (res_begin);
}
