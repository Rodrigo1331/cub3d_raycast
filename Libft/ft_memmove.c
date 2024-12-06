/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:08:43 by jode-jes          #+#    #+#             */
/*   Updated: 2023/04/26 17:13:51 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	unsigned const char	*src_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = dest;
	src_ptr = src;
	if (dest_ptr < src_ptr)
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	else
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
			*(--dest_ptr) = *(--src_ptr);
	}
	return (dest);
}

/* int	main(void)
{
	const char src[] = "Hello World";
	char dest[3] = "Hi";
	size_t size = 5;
	printf("src before ft_memmove: %s\n", src);
	printf("dest before ft_memmove: %s\n", dest);
	ft_memmove(dest, src, size);
	printf("src after ft_memmove: %s\n", src);
	printf("dest after ft_memmove: %s\n\n", dest);

	const char src_1[] = "Hello World";
	char dest_1[3] = "Hi";
	size_t size_1 = 5;
	printf("src before memmove: %s\n", src_1);
	printf("dest before memmove: %s\n", dest_1);
	memmove(dest_1, src_1, size_1);
	printf("src after memmove: %s\n", src_1);
	printf("dest after memmove: %s\n", dest_1);
} */