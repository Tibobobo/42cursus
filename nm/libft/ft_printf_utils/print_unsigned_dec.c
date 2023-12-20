/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:48:05 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/23 16:30:59 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	num_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*unsigned_itoa(unsigned int n)
{
	char	*res;
	int		len;

	len = num_len(n);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (n > 0)
	{
		res[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

int	print_unsigned_dec(unsigned int n)
{
	int		len;
	char	*res;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		len = 1;
	}
	else
	{
		res = unsigned_itoa(n);
		len = ft_strlen(res);
		print_str(res);
		free (res);
	}
	return (len);
}
