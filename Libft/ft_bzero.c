/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:15:54 by jode-jes          #+#    #+#             */
/*   Updated: 2023/04/27 12:37:48 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n-- > 0)
	{
		*p++ = '\0';
	}
}

/* int main ()
{
	char str [] = "[h][e][l][l][o], world!";
	printf("\nBefore ft_bzero: %s\n", str);
	ft_bzero(str, sizeof(str));
	printf("After ft_bzero: %s\n\n\n", str);
	return (0);
}  */