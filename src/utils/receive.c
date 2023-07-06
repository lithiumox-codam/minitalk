/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   receive.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 21:56:09 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/18 14:11:26 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

extern t_server	g_server;

/**
 * @brief Enlarge the message buffer to fit the new message.
*/
static void	enlarge_message(void)
{
	char	*new_message;
	int		old_length;
	int		new_length;

	g_server.buffer[g_server.i] = '\0';
	if (g_server.message != NULL)
		old_length = ft_strlen(g_server.message);
	else
		old_length = 0;
	new_length = old_length + g_server.i + 1;
	new_message = (char *)malloc(new_length);
	if (new_message == NULL)
		exit(EXIT_FAILURE);
	if (g_server.message)
	{
		ft_strcpy(new_message, g_server.message);
		free(g_server.message);
	}
	else
		new_message[0] = '\0';
	ft_strcat(new_message, g_server.buffer);
	g_server.message = new_message;
	g_server.i = 0;
}

/**
 * @brief Add the character to the message buffer.
 * 
 * @param c The character to add.
 */
static void	manipulate_struct(char c)
{
	if (c != '\0')
	{
		g_server.buffer[g_server.i] = c;
		g_server.i = g_server.i + 1;
	}
	else
		g_server.complete = true;
}

/**
 * @brief Print the message and reset the struct.
 * 
 * @param info Information about the signal.
 * @param c The character to add.
 */
static void	print_and_readjust_struct(siginfo_t *info, char c)
{
	if (g_server.complete)
	{
		ft_printf("%s\n", g_server.message);
		g_server.complete = false;
		free(g_server.message);
		g_server.message = NULL;
	}
	else
	{
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit(EXIT_FAILURE);
	}
}

/**
 * @brief Concatenate the message buffer and the new character.
 * 
 * @param c The character to add.
 * @param info Information about the signal.
 */
static void	concat_message(char c, siginfo_t *info)
{
	if (g_server.i == BUFF_SIZE - 1 || c == '\0')
		enlarge_message();
	manipulate_struct(c);
	print_and_readjust_struct(info, c);
}

/**
 * @brief Recieve the bit and concatenate the message.
 * 
 * @param sig The signal recieved.
 * @param info Information about the signal.
 * @param context The context of the signal. (unused)
 */
void	recieve_bit(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		g_server.signal.c |= (1 << g_server.signal.bitpos);
	else if (sig == SIGUSR2)
		g_server.signal.c &= ~(1 << g_server.signal.bitpos);
	g_server.signal.bitpos++;
	if (g_server.signal.bitpos == 8)
	{
		if (g_server.signal.c == '\0')
			g_server.complete = true;
		concat_message(g_server.signal.c, info);
		g_server.signal.bitpos = 0;
		g_server.signal.c = '\0';
	}
}
