/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:16:46 by jode-jes          #+#    #+#             */
/*   Updated: 2024/03/12 19:31:25 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*c;
	bool	sign;
	int		len;
	int		base;

	base = 10;
	sign = n < 0;
	len = ft_intlen(n, base) + sign;
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (sign)
	{
		*c = '-';
		c[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len-- - sign)
	{
		c[len] = n % 10 + '0';
		n = n / 10;
	}
	return (c);
}

/* int	main(void)
{
	int num = -12345;
	char *str = ft_itoa(num);
	printf("Number: %d\n", num);
	printf("String: %s\n", str);
	free(str);
	return (0);
} */