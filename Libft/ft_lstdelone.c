/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstdelone.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 13:48:48 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 13:49:59 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Deletes a single node from a linked list and frees its memory.
*
* @param lst A pointer to the node to be deleted.
* @param del A function pointer to a function that takes a void pointer
* and frees the memory associated with the content of the node.
* @return None
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	lst->content = malloc(1);
	lst->next = NULL;
	ft_lstdelone(lst, free);
	printf("ok\n");
	return (0);
}
*/
