/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:01:11 by fwatanab          #+#    #+#             */
/*   Updated: 2023/05/25 16:05:28 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sign_type(int c, va_list args)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = put_char(va_arg(args, int));
	else if (c == 's')
		n = put_string(va_arg(args, char *));
	else if (c == 'p')
		n = put_pointer((unsigned long long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		n = put_number(va_arg(args, int));
	else if (c == 'u')
		n = put_unsigned_number(va_arg(args, unsigned int));
	else if (c == 'x')
		n = put_hexa_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		n = put_hexa_upper(va_arg(args, unsigned int));
	else if (c == '%')
	{
		ft_putstr_fd("%", 1);
		n++;
	}
	return (n);
}

int	check_sign_print(const char *mstr, va_list args)
{
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	while (mstr[i])
	{
		if (mstr[i] == '%')
		{
			i++;
			len += sign_type(mstr[i], args);
		}
		else
		{
			ft_putchar_fd(mstr[i], 1);
			len++;
		}
		i++;
	}
	if (!mstr[i])
		return (len);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	char	*mstr;
	va_list	args;

	len = 0;
	mstr = ft_strdup(str);
	if (!mstr)
		return (0);
	va_start(args, str);
	len = check_sign_print(mstr, args);
	va_end(args);
	free (mstr);
	return (len);
}
