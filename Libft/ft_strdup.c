/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:37:31 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/03 12:22:56 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* int	main(void)
{
	char str1[] = "Hello World!";
	char str2[] = "";
	printf("\nOriginal string: %s\n", str1);
	printf("ft_strdup result: %s\n", ft_strdup(str1));
	printf("New string: %s\n\n", str2);

	char str3[] = "Hello World!";
	char *str4 = strdup(str3);
	printf("\nOriginal string: %s\n", str3);
	printf("strdup result: %s\n", str4);
	printf("New string: %s\n\n", str4);
	free(str4);
	return (0);
} */