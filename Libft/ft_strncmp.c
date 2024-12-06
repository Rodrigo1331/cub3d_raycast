/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:01:34 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/02 13:45:00 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/* int main()
{
	char str_1 [] = "";
	char str_2 [] = "h";
	size_t n = 1;
	int result = ft_strncmp (str_1,str_2, n);
	if (result == 0)
	{
		printf("The strings are equal.\n");
	}
	else if (result < 0)
	{
		printf("String 2 is greater than string 1.\n");
	}
	else
	{
		printf("String 1 is greater than string 2.\n");
	}
	return (0);
} */