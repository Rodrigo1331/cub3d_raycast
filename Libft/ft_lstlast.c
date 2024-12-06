/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:23:41 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/11 19:53:02 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/* int main(void)
{
	// Create a list with 3 nodes
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	// Set the content of each node to a number and connect the nodes together
	node1->content = (void*)1;
	node1->next = node2;
	node2->content = (void*)2;
	node2->next = node3;
	node3->content = (void*)3;
	node3->next = NULL;

	// Call the ft_lstlast function to get the last node of the list
	t_list *last = ft_lstlast(node1);

	// Print the content of the last node
	printf("\nThe last node contains: %p\n\n", last->content);

	return (0);
} */
