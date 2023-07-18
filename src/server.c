/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:10:35 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/29 21:40:02 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	decimal_conbersion(int nbr)
{
	char	c;
	int		data;
	int		base;

	data = 0;
	base = 1;
	while (nbr)
	{
		data = data + (nbr % 10) * base;
		nbr /= 10;
		base *= 2;
	}
	c = data;
	ft_printf("%c", c);
}

void	sig_handler(int sig)
{
	static int	nbr;
	static int	byte;

	if (sig == SIGUSR1)
	{
		nbr = nbr * 10 + 0;
		byte++;
	}
	else if (sig == SIGUSR2)
	{
		nbr = nbr * 10 + 1;
		byte++;
	}
	if (byte == 8)
	{
		decimal_conbersion(nbr);
		nbr = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	while (1)
	{
	}
	return (0);
}
