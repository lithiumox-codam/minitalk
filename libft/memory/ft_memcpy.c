/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:07:17 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/14 00:36:08 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Copies n bytes from src to dst
 *
 * @param dst Address of memory to copy to
 * @param src Address of memory to copy from
 * @param n Amount of bytes to copy
 * @return void* Address of dst
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	destination = dst;
	source = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
		*(destination++) = *(source++);
	return (dst);
}
