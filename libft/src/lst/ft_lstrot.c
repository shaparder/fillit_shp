/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:36:13 by osfally           #+#    #+#             */
/*   Updated: 2019/02/16 19:58:24 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list				*ft_lstrot(t_list **lst)
{
	t_list	*head;
	t_list	*current;

	current = *lst;
	if (!current || !current->next)
		return (*lst);
	while (current->next->next)
		current = current->next;
	head = current->next;
	current->next = NULL;
	head->next = *lst;
	*lst = head;
	return (*lst);
}
