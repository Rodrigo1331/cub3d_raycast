/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:50:57 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/08 21:04:39 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (NULL);
	while (s[i])
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/* char ft_add_index (unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char str[] = "Hello";
	char *modified_str = ft_strmapi (str, ft_add_index);
	printf("\nModified str is: %s\n\n", modified_str);
	free(modified_str);
	return (0);
} */
