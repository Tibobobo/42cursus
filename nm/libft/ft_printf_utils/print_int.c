/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:47:29 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/24 09:27:58 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_int(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	print_str(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
