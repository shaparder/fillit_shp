/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:02:39 by osfally           #+#    #+#             */
/*   Updated: 2019/02/13 21:29:29 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	MACH((elem = (t_list *)malloc(sizeof(t_list))), NULL);
	if (content == NULL)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		MACH((elem->content = malloc(content_size)), NULL);
		if (elem->content == NULL)
		{
			free(elem);
			return (NULL);
		}
		ft_memcpy((elem->content), content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
