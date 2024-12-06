/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:53:18 by jode-jes          #+#    #+#             */
/*   Updated: 2023/04/27 22:46:30 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* int	main(void)
{
	const char src[] = "Hello";
	char dest[] = "World!";
	size_t dstsize = 6;
	printf("\ndest before strlcpy: %s\n\n", dest);
	//ft_strlcpy (dest, src, dstsize);

	printf("strlen after strlcpy: %zu\n\n", ft_strlcpy(dest, src, dstsize));
	printf("dest after strlcpy: %s\n\n", dest);
	return (0);
} */