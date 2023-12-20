/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:32:04 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/09 17:52:05 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_malloc_size(char const *s, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && is_in_set(s[i], set))
	{
		i++;
	}
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		i++;
		count++;
	}
	i--;
	while (is_in_set(s[i], set))
	{
		count--;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	res = malloc(sizeof(char) * (get_malloc_size(s1, set) + 1));
	if (!res)
		return (NULL);
	if (get_malloc_size(s1, set) == 0)
	{
		res[0] = '\0';
		return (res);
	}
	while (is_in_set(s1[start], set) == 1)
		start++;
	while (i < get_malloc_size(s1, set))
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
