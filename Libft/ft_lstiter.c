/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:54:36 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/10 12:57:29 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* // Example function to be applied to each node's content
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	// Create a sample list with three nodes
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = "Hello";
	node1->next = node2;
	node2->content = "World";
	node2->next = node3;
	node3->content = "!";
	node3->next = NULL;

	ft_lstiter(node1, print_content);
	// Apply print_content function to each node's content

	// Free the memory allocated for the list
	free(node1);
	free(node2);
	free(node3);

	return (0);
} */