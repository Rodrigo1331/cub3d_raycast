/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:02:44 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/02 14:00:19 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = len;
	while (i > 0)
	{
		if ((s[i]) == c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

/* int main()
{
	char s1[] = "Hello World!";
	char s2[] = "alexandre";
	char *result;

	result = ft_strrchr(s1, 'l');
	printf("'%c' last occurence in '%s' is at position %ld\n", 'l', s1, result
		- s1);
	result = ft_strrchr(s1, 'o');
	printf("'%c' last occurence in '%s' is at position %ld\n", 'o', s1, result
		- s1);
	result = ft_strrchr(s1, 'x');
	printf("'%c' last occurence in '%s' is at position %p\n", 'x', s1, result);
	result = ft_strrchr(s2, 'x');
	printf("'%c' last occurence in '%s' is at position %p\n", 'x', s2, result);

	return (0);
} */