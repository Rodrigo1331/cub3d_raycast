/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:04:27 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/16 00:36:16 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

/* int main(void)
{
	// Create a linked list with three nodes
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = malloc(sizeof(int));
	node2->content = malloc(sizeof(int));
	node3->content = malloc(sizeof(int));

	*(int *)node1->content = 1;
	*(int *)node2->content = 2;
	*(int *)node3->content = 3;

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	t_list *list = node1;

	// Print the old list
	printf("Old List: ");
	t_list *current = list;
	while (current != NULL)
	{
		printf("%d ", *(int *)current->content);
		current = current->next;
	}
	printf("\n");

	// Call ft_lstclear to delete and free the list
	ft_lstclear(&node2, &free);

	// Update the next pointer of node1 to NULL
	node1->next = NULL;

	// Print the new list (should be empty)
	printf("New List: ");
	current = list;
	while (current != NULL)
	{
		printf("%d ", *(int *)current->content);
		current = current->next;
	}
	printf("\n");

	return (0);
} */