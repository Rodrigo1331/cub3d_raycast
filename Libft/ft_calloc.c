/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:42:06 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/03 11:13:42 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	total_size;
	void	*ptr;
	char	*temp;

	total_size = nmemb * size;
	i = 0;
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	temp = (char *)ptr;
	while (i < total_size)
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}

/* int	main(void)
{
	int *ptr_1;
	int *ptr_2;
	int num_elements = 5;
	int element_size = sizeof(int);

	ptr_1 = (int *)ft_calloc(num_elements, element_size);
	if (ptr_1 == NULL)
	{
		printf("Memory allocation failed \n");
		return (1);
	}
	printf("Memory allocated using calloc \n");
	int i = 0;
	while (i < num_elements)
	{
		printf("%d", ptr_1[i]);
		i++;
	}
	printf("\n");

	ptr_2 = (int *)calloc(num_elements, element_size);
	if (ptr_2 == NULL)
	{
		printf("Memory allocation failed \n");
		return (1);
	}
	printf("Memory allocated using calloc \n");

	int j = 0;
	while (j < num_elements)
	{
		printf("%d", ptr_2[i]);
		j++;
	}
	printf("\n");

	free(ptr_1);
	free(ptr_2);

	return (0);
} */