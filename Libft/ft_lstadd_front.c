/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:07:12 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/10 11:41:03 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	new_node->next = *lst;
	*lst = new_node;
}

/* int main()
{
	t_list *lst = NULL;
	t_list *new_node;

	// Create a new node with content "world"
	new_node = ft_lstnew("world");

	// Add the new node to the beginning of the list
	ft_lstadd_front(&lst, new_node);

	// Create another new node with content "hello"
	new_node = ft_lstnew("hello");

	// Add the second new node to the beginning of the list
	ft_lstadd_front(&lst, new_node);

	// Print the contents of the list
	while (lst != NULL)
	{
		printf("\n%s\n\n", (char*)lst->content);
		lst = lst->next;
	}
	return (0);
} */
