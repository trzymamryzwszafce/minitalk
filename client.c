/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:30:22 by szmadeja          #+#    #+#             */
/*   Updated: 2025/02/27 19:43:00 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	val;
	int	i;

	res = 0;
	val = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			val = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (val * res);
}

void	ack_handler(int sig)
{
	(void)sig;
}

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	pause();
}

void	send_message(int pid, char *mes)
{
	int		i;
	int		position;
	int		bit;
	char	byte;

	i = 0;
	while (mes[i])
	{
		byte = mes[i];
		position = 7;
		while (position >= 0)
		{
			bit = (byte >> position) & 1;
			send_bit(pid, bit);
			position--;
		}
		i++;
	}
	kill(pid, SIGUSR1);
	pause();
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*mes;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (!pid)
		return (0);
	mes = argv[2];
	if (!mes)
		return (0);
	signal(SIGUSR1, ack_handler);
	send_message(pid, mes);
	ft_printf("Message sent succesfully\n");
	return (0);
}
