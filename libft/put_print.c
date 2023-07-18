/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:19 by fwatanab          #+#    #+#             */
/*   Updated: 2023/02/07 17:05:36 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	put_string(char	*str)
{
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}

int	put_number(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}

int	put_unsigned_number(unsigned int nbr)
{
	int		len;
	char	*str;

	str = unsigned_itoa(nbr);
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}

int	put_pointer(unsigned long long pointer)
{
	int					len;
	char				*str;
	unsigned long long	p2;

	len = 2;
	p2 = pointer;
	ft_putstr_fd("0x", 1);
	if (pointer == 0)
	{
		ft_putstr_fd("0", 1);
		return (3);
	}
	str = count_pointer(pointer);
	ft_putstr_fd(str, 1);
	len += pointer_size(p2);
	free(str);
	return (len);
}
