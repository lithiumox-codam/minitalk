/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 21:55:56 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/18 01:27:21 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

t_server	g_server;

/**
 * @brief This function is used to clean up the memory allocated by the server.
 * 
 */
static void	cleanup(void)
{
	if (g_server.message)
		free(g_server.message);
	if (g_server.buffer)
		free(g_server.buffer);
	g_server.message = NULL;
	g_server.buffer = NULL;
}

/**
 * @brief Init function to set the default values of the global struct.
*/
static void	init(void)
{
	g_server.complete = false;
	g_server.i = 0;
	g_server.message = ft_strdup("");
	g_server.buffer = ft_calloc(BUFF_SIZE, sizeof(char));
	g_server.signal.c = '\0';
	g_server.signal.bitpos = 0;
	if (!g_server.message || !g_server.buffer)
		exit(EXIT_FAILURE);
}

/**
 * @brief This funcrtion encapsulates the logic of the server.
*/
void	server(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = recieve_bit;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	init();
	atexit(cleanup);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}
