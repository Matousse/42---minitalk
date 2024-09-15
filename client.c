/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:23:01 by dmathis           #+#    #+#             */
/*   Updated: 2024/08/15 17:16:42 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_flag;

void	handle_response(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		g_flag = 1;
}

void	send_char_to_server(pid_t pid, char c)
{
	int	bits;
	int	delay;

	bits = 0;
	while (bits < 8)
	{
		if ((c >> (bits)) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits++;
		delay = 0;
		while (g_flag == 0)
		{
			if (delay == 200)
				exit(1);
			usleep(100);
			delay++;
		}
		g_flag = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	struct sigaction	action;

	if (argc != 3)
		return (printf("Incorrect parameters"), 0);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Incorrect PID\n"), 1);
	i = 0;
	action.sa_sigaction = handle_response;
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (argv[2][i])
	{
		send_char_to_server(pid, argv[2][i]);
		i++;
	}
	send_char_to_server(pid, '\0');
	return (0);
}
