/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:25:35 by maroth            #+#    #+#             */
/*   Updated: 2023/10/27 20:27:58 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the last node of the list.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	last_node = lst;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}
