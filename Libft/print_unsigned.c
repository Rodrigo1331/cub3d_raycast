/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:00:31 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/07 08:36:59 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_nbr_right(char *nbr, int *flags)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < flags[7])
		i += write(1, " ", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putstr_fd(nbr, 1);
	free(nbr);
	return (i + j);
}

static int	print_nbr_left(char *nbr, int *flags)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putstr_fd(nbr, 1);
	free(nbr);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (i + j);
}

int	print_unsigned(unsigned int n, int *flags)
{
	int		len;
	char	*nbr;

	nbr = ft_itoapositive(n);
	len = ft_intlen(n, 10);
	if (flags[5] && !flags[6] && !n)
		flags[5] += len--;
	if (flags[4] && !flags[5])
	{
		flags[6] = flags[7];
		flags[7] = 0;
	}
	if (flags[6] > len)
		flags[7] -= flags[6];
	else
		flags[7] -= len;
	if (flags[5])
		flags[6] -= len;
	else
		flags[6] -= len;
	if (flags[3])
		return (len + print_nbr_left(nbr, flags));
	return (len + print_nbr_right(nbr, flags));
}
