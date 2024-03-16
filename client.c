/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:19:16 by ebouboul          #+#    #+#             */
/*   Updated: 2024/03/16 15:19:18 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

void	ft_send_bit(int pid, char *str)
{
	int	i;
	int	shifting;

	i = 0;
	while (str[i])
	{
		shifting = 7;
		while (shifting >= 0)
		{
			if ((str[i] >> shifting) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(9);
			shifting--;
		}
		i++;
	}
}

int	ft_check_pid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		if (ft_check_pid(av[1]) == 0)
			return (ft_printf("chech the pid please :) \n"));
		pid = ft_atoi(av[1]);
		str = av[2];
		ft_send_bit(pid, str);
	}
	else
		return (ft_printf("u need to type 2 args\n"));
}
