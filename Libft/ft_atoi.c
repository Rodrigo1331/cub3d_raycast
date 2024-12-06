/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:31:00 by jode-jes          #+#    #+#             */
/*   Updated: 2023/09/21 12:10:04 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = sign * (-1);
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result * sign);
}
/* int	main(void)
{
	const char str_1[] = " -  +1234";
	int result = ft_atoi(str_1);
	printf("\nchar converted to int: %d\n", result);

	char str_2[] = " -  +1234";
	printf("\nchar converted to int: %d\n\n", atoi(str_2));
	return (0);
} */