/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 18:27:16 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/14 00:38:44 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a number to a file descriptor
 *
 * @param n The number to write
 * @param fd The file descriptor to write to
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		n = n % 10;
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd((n % 10) + '0', fd);
}
