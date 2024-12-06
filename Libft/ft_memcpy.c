/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:57:48 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/03 18:45:58 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while (size--)
	{
		*dest_ptr++ = *src_ptr++;
	}
	return (dest);
}

/* int main()
{
	const char src_1 [] = "Hello World";
	char dest_1 [20] = "1234567";
	size_t size_1 = sizeof(src_1);
	printf("\nsrc_1 string before ft_memcpy: %s\n", src_1);
	printf("dest_1 string before ft_memcpy: %s\n", dest_1);
	ft_memcpy (dest_1, src_1, size_1);
	printf("\nsrc_1 string after ft_memcpy: %s\n", src_1);
	printf("dest_1 string after ft_memcpy: %s\n", dest_1);

	const char src_2 [] = "Hello World";
	char dest_2 [20] = "1234567";
	size_t size_2 = sizeof(src_2);
	printf("\n\nsrc_2 string before memcpy: %s\n", src_2);
	printf("dest_2 string before memcpy: %s\n", dest_2);
	memcpy (dest_2, src_2, size_2);
	printf("\nsrc_2 string after memcpy: %s\n", src_2);
	printf("dest_2 string after memcpy: %s\n\n", dest_2);

	return (0);
} */