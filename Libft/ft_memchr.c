/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:30:12 by jode-jes          #+#    #+#             */
/*   Updated: 2023/04/27 11:20:29 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n-- > 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char str[] = "Hello, world!";
	char c = 'w';
	size_t n = strlen(str);

	// Test ft_memchr
	void *p = ft_memchr(str, c, n);
	if (p != NULL)
		printf("\nft_memchr found '%c' at position %ld\n\n", c, (p
					- (void *)str));
	else
		printf("ft_memchr did not find '%c'\n\n", c);

	// Test memchr
	p = memchr(str, c, n);
	if (p != NULL)
		printf("memchr found '%c' at position %ld\n\n", c, (p - (void *)str));
	else
		printf("memchr did not find '%c'\n\n", c);

	return (0);
} */