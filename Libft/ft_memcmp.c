/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:28:06 by jode-jes          #+#    #+#             */
/*   Updated: 2023/04/27 22:49:57 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n-- > 0)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
	}
	return (0);
}

/* int main()
{
	char str1[] = "Hello, world!";
	char str2[] = "Hello, friends!";
	int result = ft_memcmp(str1, str2, strlen(str1));
	if (result == 0)
	{
		printf("The strings are equal.\n");
	}
	else if (result < 0)
	{
		printf("String 1 is less than string 2.\n");
	}
	else
	{
		printf("String 1 is greater than string 2.\n");
	}
	return (0);
} */
