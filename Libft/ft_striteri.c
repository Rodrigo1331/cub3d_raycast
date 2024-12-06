/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:05:30 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/08 22:10:12 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void ft_add_index (unsigned int i, char *c)
{
	*c += i;
}

int	main(void)
{
	char str[] = "Hello";
	printf("\nOriginal str is: %s\n\n", str);
	ft_striteri (str, ft_add_index);
	printf("\nModified str is: %s\n\n\n", str);
	return (0);
} */