/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:46:55 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/24 09:27:25 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_dec(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	print_str(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
