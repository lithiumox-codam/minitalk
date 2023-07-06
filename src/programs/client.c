/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 01:04:12 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/18 01:16:59 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

t_client	g_client;

/**
 * @brief Handler for the SIGUSR1 signal
 * 
 * @param sig The signal
*/
static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_client.received = true;
}

/**
 * @brief Initializes the client
 * 
 * @param pid The pid of the server process
*/
static void	init(char *pid)
{
	g_client.pid = ft_atoi(pid);
	g_client.received = false;
	g_client.i = -1;
	if (g_client.pid <= 0 || kill(g_client.pid, 0) == -1)
	{
		ft_printf("Invalid PID\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Handler to send a string to the server process
 * 
 * @param av Argument list containing the pid and message
*/
void	client(char **av)
{
	struct sigaction	sa;
	int					pid;

	init(av[1]);
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (*av[2])
	{
		g_client.received = false;
		send_char(*av[2]);
		while (!g_client.received)
			;
		av[2]++;
	}
	send_char('\0');
	ft_printf("Message sent\n");
}
