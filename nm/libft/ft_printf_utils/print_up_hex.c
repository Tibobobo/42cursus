/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_up_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:49:17 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/24 09:47:12 by tgrasset         ###   ########.fr       */
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

static void	put_up_hex(unsigned int n)
{
	if (n >= 16)
	{
		put_up_hex(n / 16);
		put_up_hex(n % 16);
	}
	else if (n < 10)
		ft_putchar_fd((n + '0'), 1);
	else
		ft_putchar_fd((n - 10 + 'A'), 1);
}

int	print_up_hex(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = len + write(1, "0", 1);
	else
	{
		put_up_hex(n);
		len = len + get_hexa_len(n);
	}
	return (len);
}
