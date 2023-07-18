/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexadecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:13 by fwatanab          #+#    #+#             */
/*   Updated: 2023/02/07 17:05:40 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	put_hexa_lower(unsigned int nbr)
{
	int				len;
	char			*str;
	unsigned int	p2;

	len = 0;
	p2 = nbr;
	if (nbr == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	str = count_pointer(nbr);
	ft_putstr_fd(str, 1);
	len += pointer_size(p2);
	free(str);
	return (len);
}

int	put_hexa_upper(unsigned int nbr)
{
	int				len;
	char			*str;
	unsigned int	p2;

	len = 0;
	p2 = nbr;
	if (nbr == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	str = count_pointer(nbr);
	str = str_upper(str);
	ft_putstr_fd(str, 1);
	len += pointer_size(p2);
	free(str);
	return (len);
}
