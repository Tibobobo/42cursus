/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:01:00 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/09 10:14:13 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= size)
		return (slen + size);
	while (i < size - dlen && src[i] != '\0')
	{
		dst[i + dlen] = src[i];
		i++;
	}
	if (i < size - dlen)
		dst[i + dlen] = '\0';
	else
		dst[i + dlen - 1] = '\0';
	return (dlen + slen);
}
