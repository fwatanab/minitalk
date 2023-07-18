/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:26 by fwatanab          #+#    #+#             */
/*   Updated: 2023/02/07 17:02:27 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count(unsigned int n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i - 1);
}

char	*unsigned_itoa(unsigned int n)
{
	char		*str;
	size_t		n_size;

	n_size = count(n);
	str = (char *)malloc(sizeof(char) * (n_size + 1));
	if (str == NULL)
		return (NULL);
	str[n_size] = '\0';
	while (n_size--)
	{
		str[n_size] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
