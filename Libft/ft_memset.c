/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:16:31 by jode-jes          #+#    #+#             */
/*   Updated: 2023/04/20 12:55:27 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n-- > 0)
	{
		*p++ = (unsigned char)c;
	}
	return (s);
}

/* int main ()
{
	char str [] = {48, 49};
	printf("string %s \n", str);
	printf("return (of s is: %p \n", ft_memset(str, 57, 4)));
	char *strp = (char *) ft_memset(str, 57, 4);
	printf("return (of s is: %s \n", strp));
	return(0);
} */