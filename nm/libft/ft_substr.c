/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:27:46 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/09 17:35:04 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
