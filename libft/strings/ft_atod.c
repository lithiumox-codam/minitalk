/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/21 11:52:58 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/21 21:39:22 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the power of a number
 *
 * @param str The number to calculate the power of
 * @param decimal The power to calculate
 * @return char* The string representation of the integer
 */
static char	*ft_get_decimal(char *str, double *decimal)
{
	if (*str == '.')
		str++;
	while (*str)
	{
		*decimal = *decimal * 10 + (*str - '0');
		str++;
	}
	return (str);
}

/**
 * @brief Converts a string to a double
 *
 * @param str The string to convert
 *
 * @return double The converted string
 */
double	ft_atod(char *str)
{
	double	result;
	double	decimal;
	int		sign;

	result = 0;
	decimal = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	str = ft_get_decimal(str, &decimal);
	decimal /= ft_pow(10, ft_intlen((int)decimal));
	return (sign * (result + decimal));
}
