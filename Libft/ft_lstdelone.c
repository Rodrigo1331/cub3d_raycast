/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:42:13 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/10 12:51:33 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}

/* int main()
 {
	// create a linked list with three nodes
	t_list *node1 = ft_lstnew ("node 1 content 42");
	t_list *node2 = ft_lstnew("node 2 content 42 twice");
	t_list *node3 = ft_lstnew ("node 3 content 42 3 times");
	node1 -> next = node2;
	node2 -> next = node3;

	// free the list with ft_lstdelone

	ft_lstdelone(node1, &free);

	// attempt to print the list to confirm it has been freed.
	It will print the nodes that weren´t deleted,
	but not the one that was.
	printf("\n%s\n\n", (char*)node2->content); // this should print
	printf("\n%s\n\n", (char*)node3->content); // this should print
	printf("\n%s\n\n", (char*)node1->content);
	// this should cause a segmentation fault
	return (0);
 } */
/*
int	main(void)
{
	t_list *node = ft_lstnew(malloc(sizeof(int)));
	*((int*)node->content) = 42;

	printf("Content before freeing: %d\n", *((int*)node->content));

	ft_lstdelone(node, &free);

	printf("Content after freeing: %d\n", *((int*)node->content));

	return (0);
} */
