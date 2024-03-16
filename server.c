/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:19:48 by ebouboul          #+#    #+#             */
/*   Updated: 2024/03/16 15:19:50 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

void	bit(int signl)
{
	static char	char_bit;
	static int	num_bit;

	if (num_bit <= 7)
	{
		char_bit = (char_bit << 1);
		if (signl == SIGUSR1)
			char_bit++;
		num_bit++;
	}
	if (char_bit && num_bit > 7)
	{
		ft_printf("%c", char_bit);
		char_bit = 0;
		num_bit = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("my pid id : %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, bit);
		signal(SIGUSR2, bit);
	}
}
