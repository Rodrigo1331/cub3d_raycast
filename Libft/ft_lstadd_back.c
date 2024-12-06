/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:23 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/15 12:47:48 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*temp;

	if (!lst || !new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

/* int main()
{
	t_list	*lst;
	t_list	*new_node;

	lst = NULL;
	// Create a new node with content "world"
	new_node = ft_lstnew("world");
	// Add the new node to the end of the list
	ft_lstadd_back(&lst, new_node);
	// Create another new node with content "hello"
	new_node = ft_lstnew("hello");
	// Add the second new node to the end of the list
	ft_lstadd_back(&lst, new_node);
	// Print the contents of the list
	while (lst != NULL)
	{
		printf("\n%s\n\n", (char*)lst->content);
		lst = lst->next;
	}
	return (0);
}
 */