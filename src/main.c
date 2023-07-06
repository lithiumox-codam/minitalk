/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 00:04:27 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/18 01:35:31 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

/**
 * @brief The main function of the program. It checks which program is called
 * and calls the corresponding function.
 *
 * @param ac The amount of arguments (1 or 3)
 * @param av The arguments
 * @return int 0 on success, 1 on failure
 */
int	main(int ac, char **av)
{
	if (ft_strnstr(av[0], "server", 50) && ac == 1)
		server();
	else if (ft_strnstr(av[0], "client", 50) && ac == 3)
		client(av);
	else
		ft_printf("Usage: ./[server|client] ([PID] [MESSAGE])\n");
	return (0);
}
