/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:10:27 by fwatanab          #+#    #+#             */
/*   Updated: 2023/07/06 15:14:26 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	push_message(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				free(str);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				free(str);
				exit(1);
			}
		}
		i++;
		usleep(100);
	}
}

static void	send_remainder(int pid, size_t byte)
{
	byte = 8 - byte;
	while (byte)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit (1);
		byte--;
		usleep(100);
	}
}

static void	binary_conversion(int pid, int c)
{
	int		nbr;
	int		base;
	size_t	byte;
	char	*str;

	nbr = 0;
	base = 1;
	byte = 0;
	while (c)
	{
		nbr = nbr + (c % 2) * base;
		c /= 2;
		base *= 10;
		byte++;
	}
	send_remainder(pid, byte);
	str = ft_itoa(nbr);
	if (!str)
		return ;
	push_message(pid, str);
	free(str);
}

static void	repeat_message(int pid, char *str)
{
	int	tmp;

	while (*str)
	{
		tmp = *str;
		binary_conversion(pid, tmp);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (1);
	repeat_message(pid, argv[2]);
	return (0);
}
