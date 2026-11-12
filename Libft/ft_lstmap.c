/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstmap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 14:03:43 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/27 10:09:32 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Applies a function to each element of a linked list,
* creating a new list with the results.
* @param lst A pointer to the first node of the linked list.
* @param f A function pointer that takes a void pointer as an argument
* and returns a void pointer.
* The function is applied to the content of each node in the list.
* @param del A function pointer that takes a void pointer as an argument
* and frees the memory associated with it.
* This function is used to free the content of a node
* if memory allocation fails during the creation of the new list.
* @return A pointer to the first node of the new linked list,
* or NULL if memory allocation fails.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			if (del)
				del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include <stdio.h>
#include <string.h>

static void	*dup_content(void *content)
{
	char	*dst;

	dst = malloc(strlen((char *)content) + 1);
	if (!dst)
		return (NULL);
	strcpy(dst, (char *)content);
	return (dst);
}

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	*map;

	a.content = "a";
	a.next = &b;
	b.content = "b";
	b.next = NULL;
	map = ft_lstmap(&a, dup_content, free);
	printf("%s %s\n", (char *)map->content, (char *)map->next->content);
	free(map->next->content);
	free(map->next);
	free(map->content);
	free(map);
	return (0);
}
*/
