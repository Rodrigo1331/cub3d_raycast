/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:42:39 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/04 00:03:28 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_length;
	int		i;
	int		j;

	total_length = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * total_length + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

/* int main()
{
	const char s1[] = "Hello";
	const char s2[] = " World!";
	printf("\nword joined: %s\n\n", ft_strjoin(s1, s2));
	return (0);
} */