/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_low_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:48:41 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/24 09:44:02 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_hexa_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	put_low_hex(unsigned int n)
{
	if (n >= 16)
	{
		put_low_hex(n / 16);
		put_low_hex(n % 16);
	}
	else if (n < 10)
		ft_putchar_fd((n + '0'), 1);
	else
		ft_putchar_fd((n - 10 + 'a'), 1);
}

int	print_low_hex(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = len + write(1, "0", 1);
	else
	{
		put_low_hex(n);
		len = len + get_hexa_len(n);
	}
	return (len);
}
