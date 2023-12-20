/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:46:00 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/24 10:06:33 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_hexa_len(unsigned long long n)
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

static void	put_address(unsigned long long n)
{
	if (n >= 16)
	{
		put_address(n / 16);
		put_address(n % 16);
	}
	else if (n < 10)
		ft_putchar_fd((n + '0'), 1);
	else
		ft_putchar_fd((n - 10 + 'a'), 1);
}

int	print_ptr(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (print_str("(nil)"));
	len = len + write(1, "0x", 2);
	put_address(n);
	len = len + get_hexa_len(n);
	return (len);
}
