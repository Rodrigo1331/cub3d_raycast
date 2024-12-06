/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:03:01 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/10 12:24:23 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/* int main()
{
	t_list *lst = NULL;
	t_list *new_node;

	// Create a new node with content "world"
	new_node = ft_lstnew("world");

	// Add the new node to the end of the list
	ft_lstadd_back(&lst, new_node);

	// Create another new node with content "hello"
	new_node = ft_lstnew("hello");

	// Add the second new node to the end of the list
	ft_lstadd_back(&lst, new_node);

	// Get the size of the list
	int size = ft_lstsize(lst);

	// Print the size of the list
	printf("\nSize of list: %d\n\n", size);

	return (0);
} */
