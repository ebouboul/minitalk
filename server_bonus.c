/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:19:36 by ebouboul          #+#    #+#             */
/*   Updated: 2024/03/16 15:19:39 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

void	bit(int signum, siginfo_t *info, void *context)
{
	static char	char_bit;
	static int	num_bit;

	(void)context;
	if (num_bit <= 7)
	{
		char_bit = (char_bit << 1);
		if (signum == SIGUSR1)
			char_bit++;
		num_bit++;
	}
	if (char_bit && num_bit > 7)
	{
		ft_printf("%c", char_bit);
		char_bit = 0;
		num_bit = 0;
	}
	else if (char_bit == '\0' && num_bit > 7)
	{
		kill(info->si_pid, SIGUSR1);
		char_bit = 0;
		num_bit = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = bit;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("my pid id : %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}
