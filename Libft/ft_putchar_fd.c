/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:35:35 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/08 23:47:18 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main(void)
{
	// Test the ft_putchar_fd function
	char c = 'A';           // Character to output
	int fd = STDOUT_FILENO; // File descriptor for standard output.

	// Output the character to the given file descriptor
	ft_putchar_fd(c, fd);

	return (0);
} */