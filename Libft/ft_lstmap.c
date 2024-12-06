/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:44:27 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/10 13:02:12 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelem;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newelem = ft_lstnew(f(lst->content));
		if (!(newelem))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newelem);
		lst = lst->next;
	}
	return (newlst);
}

// Test function: Multiply each element by 2
void	*multiply_by_two(void *n)
{
	int	*new_n;

	new_n = malloc(sizeof(int));
	if (new_n == NULL)
		return (NULL);
	*new_n = *((int *)n) * 2;
	return (new_n);
}

// Test function: Free the memory occupied by an integer
void	del_int(void *n)
{
	free(n);
}

/* int main(void)
{
	t_list *lst = NULL;
	t_list *new_lst = NULL;
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;

	// Create the initial list
	ft_lstadd_back(&lst, ft_lstnew(&n1));
	ft_lstadd_back(&lst, ft_lstnew(&n2));
	ft_lstadd_back(&lst, ft_lstnew(&n3));

	// Apply ft_lstmap to multiply each element by 2
	new_lst = ft_lstmap(lst, multiply_by_two, del_int);

	// Print the new list
	t_list *current = new_lst;
	while (current)
	{
		printf("%d ", *((int *)(current->content)));
		current = current->next;
	}
	printf("\n");

	return (0);
}  */