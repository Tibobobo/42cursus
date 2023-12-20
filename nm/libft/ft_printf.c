/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:23:59 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/07 10:35:07 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_conv(va_list args, char c)
{
	int	ret_value;

	ret_value = 0;
	if (c == 'c')
		ret_value = print_char(va_arg(args, int));
	else if (c == 's')
		ret_value = print_str(va_arg(args, char *));
	else if (c == 'p')
		ret_value = print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd')
		ret_value = print_dec(va_arg(args, int));
	else if (c == 'i')
		ret_value = print_int(va_arg(args, int));
	else if (c == 'u')
		ret_value = print_unsigned_dec(va_arg(args, unsigned int));
	else if (c == 'x')
		ret_value = print_low_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		ret_value = print_up_hex(va_arg(args, unsigned int));
	else if (c == '%')
		ret_value = print_percent();
	return (ret_value);
}

static int	is_placeholder(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	conversion(va_list args, char c)
{
	if (is_placeholder(c, "cspdiuxX%") == 1)
		return (print_conv(args, c));
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(c, 1);
		return (2);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_count;

	char_count = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			char_count++;
		}
		else if (*(str + 1) != '\0')
		{
			str++;
			char_count = char_count + conversion(args, *str);
		}
		str++;
	}
	va_end(args);
	return (char_count);
}
