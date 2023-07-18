/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:00:32 by fwatanab          #+#    #+#             */
/*   Updated: 2023/02/07 17:06:38 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_size(uintptr_t pointer)
{
	int	len;

	len = 0;
	while (pointer != 0)
	{
		pointer /= 16;
		len++;
	}
	return (len);
}

static char	*change_pointer(uintptr_t p1, char *str, int len)
{
	while (p1 != 0)
	{
		if ((p1 % 16) < 10)
			str[len - 1] = (p1 % 16) + '0';
		else
			str[len - 1] = (p1 % 16 - 10) + 'a';
		p1 /= 16;
		len--;
	}
	return (str);
}

char	*count_pointer(uintptr_t pointer)
{
	int			len;
	char		*str;
	uintptr_t	p1;

	p1 = pointer;
	if (pointer == 0)
		ft_strdup("0");
	len = 0;
	while (pointer != 0)
	{
		pointer /= 16;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = change_pointer(p1, str, len);
	return (str);
}
