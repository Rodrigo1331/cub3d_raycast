/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:17:10 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/15 10:12:35 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* int main(void)
{
	t_data content_values = {42, 3.14, "hello"}; // define the content values
	t_data *content_ptr = &content_values;
		// get a pointer to the content struct
	t_list *node = ft_lstnew(content_ptr);
		// create a new node with the content struct pointer

	if (node == NULL) { // check if ft_lstnew failed to create a new node
		printf("Failed to create a new node!\n");
		return (1);
	}

	printf("New node created successfully!\n");
	printf("Content values of the new node: %d, %f, %s\n",
			node->content->value1, node->content->value2,
			node->content->value3); // print the content values of the new node

	return (0);
} */