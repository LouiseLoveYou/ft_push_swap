/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstnew.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 09:36:52 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 09:55:22 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Allocates and initializes a new list node with the given content.
* @param content The content to be stored in the new node.
* @return A pointer to the newly created list node,
* or NULL if memory allocation fails.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("a");
	printf("%s\n", (char *)lst->content);
	free(lst);
	return (0);
}
*/
