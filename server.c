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

void	handle_signal(int sig)
{
	static int	bits;
	static int	position;

	bits = 0;
	position = 0;
	if (sig == SIGUSR1)
		bits |= (0 << position);
	else if (sig == SIGUSR2)
		bits |= (0 << position);
	position++;
	if (position == 8)
	{
		ft_printf("%c", (char)bits);
		if (bits == '\0')
			ft_printf("%c", (char)bits);
		bits = 0;
		position = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid = %d", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		;
	return (0);
}
