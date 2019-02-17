/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:59:18 by osfally           #+#    #+#             */
/*   Updated: 2019/02/16 20:00:23 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list				*ft_lstrotback(t_list **lst)
{
	t_list	*head;
	t_list	*current;

	head = *lst;
	current = *lst;
	if (!current || !current->next)
		return (*lst);
	*lst = current->next;
	while (current->next)
		current = current->next;
	current->next = head;
	head->next = NULL;
	return (*lst);
}
