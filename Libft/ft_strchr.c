/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:43:46 by jode-jes          #+#    #+#             */
/*   Updated: 2024/02/22 17:47:18 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	if (!s)
		return (0);
	a = (char *)s;
	while (*a)
	{
		if (*a == (char)c)
			return (a);
		a++;
	}
	if (*a == (char)c)
		return (a);
	return (NULL);
}

/* int main()
{
	char s[] = "Hello World!";
	int c = 'W';
	ft_strchr(s, c);
	return (0);
} */
