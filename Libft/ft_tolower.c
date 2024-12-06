/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:12:00 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/03 17:46:44 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/* int main()
{
	int c = 'D';
	printf("\nBefore tolower: %c\n", c);
	char result = ft_tolower(c);
	printf("\nAfter tolower: %c\n\n", result);
	return (0);
} */