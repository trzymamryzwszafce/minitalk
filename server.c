/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <szmadeja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:08:22 by szmadeja          #+#    #+#             */
/*   Updated: 2025/02/27 19:38:54 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	bits;
	static int	position;
	static int	c_pid = 0;

	(void) context;
	if (c_pid == 0)
		c_pid = info->si_pid;
	if (sig == SIGUSR2)
		bits |= (1 << position);
	position++;
	if (position == 8)
	{
		if (bits == '\0')
		{
			ft_printf("\n");
			kill(c_pid, SIGUSR1);
			c_pid = 0;
		}
		else
			ft_printf("%c", bits);
		bits = 0;
		position = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("pid = %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
