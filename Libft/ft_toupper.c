/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:11:48 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/03 17:43:36 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/* int main()
{
	int c = 'd';
	printf("\nBefore toupper: %c\n", c);
	char result = ft_toupper(c);
	printf("\nAfter toupper: %c\n\n", result);
	return (0);
} */