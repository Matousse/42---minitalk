/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:22:56 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/15 16:31:42 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_init;

void	writeall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	stock_chars(char c)
{
	char			*temp;
	static char		*full_string = NULL;
	static size_t	total_len;

	temp = ft_calloc(total_len + 2, sizeof(char));
	if (temp == NULL)
		return ;
	if (full_string)
	{
		ft_memcpy(temp, full_string, total_len);
		free(full_string);
	}
	full_string = temp;
	full_string[total_len] = c;
	full_string[total_len + 1] = '\0';
	total_len++;
	if (c == '\0')
	{
		writeall(full_string);
		free(full_string);
		full_string = NULL;
		total_len = 0;
	}
}

void	convert_bits(int sig, siginfo_t *info, void *ucontent)
{
	static char	c;
	static int	bit_number;

	(void)ucontent;
	if (g_init != 0)
	{
		bit_number = 0;
		g_init = 1;
	}
	if (sig == SIGUSR1)
		c |= (1 << bit_number);
	bit_number++;
	if (bit_number == 8)
	{
		bit_number = 0;
		if (!c)
		{
			stock_chars(c);
			return ((void)kill(info->si_pid, SIGUSR2));
		}
		stock_chars(c);
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("\nServer PID = %d\n", pid);
	g_init = 0;
	action.sa_sigaction = convert_bits;
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
