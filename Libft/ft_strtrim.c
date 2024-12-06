/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:11:13 by jode-jes          #+#    #+#             */
/*   Updated: 2024/02/23 20:16:02 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_build_newstring(char *newstring, char const *s1, size_t i, size_t j)
{
	size_t	x;

	x = 0;
	while (j > i)
		newstring[x++] = s1[i++];
	newstring[x] = '\0';
	return (newstring);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	if (!set || !*set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && s1[j] && ft_is_set(s1[j], set))
		j--;
	if (i > j)
		return (ft_strdup(""));
	j++;
	new_str = (char *)malloc(sizeof(char) * ((j - i) + 1));
	if (!new_str)
		return (NULL);
	return (ft_build_newstring(new_str, s1, i, j));
}

/* int	main(void)
{
	char s[] = "  \f \r1 3Hello! 65 \n  \t";
	char set[] = "1 3 t\n\r\f\v56 \t";
	printf("String trimmed: %s \n", ft_strtrim(s, set));
	return (0);
	//find the beginning of the str:
	//while(s1[i] && ft_is_set(s1[i], set))
	//	i++;
	//    if it founds the character 'H' in the set, it stops.
	//	Otherwise,it passes to the front.
	//find the end of the str:
	//while (j > i && s1[j] && ft_is_set(s1[j], set))
	//	j--;
	//if it founds the character '!' in the set, it stops.
	//Otherwise, it passes to the front, going backwords.
} */
