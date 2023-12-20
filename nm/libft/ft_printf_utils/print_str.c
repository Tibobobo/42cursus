/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:33:09 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/23 16:30:47 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_str(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
		ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
