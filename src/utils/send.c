/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   send.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 14:06:53 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/18 01:31:22 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

extern t_client	g_client;

/**
 * @brief Send a bit to the server process
 * 
 * @param bit The bit to send
 */
static void	send_bit(int bit)
{
	if (bit && kill(g_client.pid, SIGUSR1) == -1)
		exit(1);
	if (!bit && kill(g_client.pid, SIGUSR2) == -1)
		exit(1);
	usleep(50);
}

/**
 * @brief Send a character to the server process
 * 
 * @param c The character to send
 */
void	send_char(char c)
{
	while (g_client.i++ < 7)
		send_bit((c >> g_client.i) & 1);
	g_client.i = -1;
}
