/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:39:23 by osfally           #+#    #+#             */
/*   Updated: 2019/02/16 19:30:47 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			ft_lstswap(t_list *n1, t_list *n2)
{
	void		*tmp_c;
	size_t		tmp_cs;

	tmp_c = n1->content;
	tmp_cs = n1->content_size;

	n1->content = n2->content;
	n1->content_size = n2->content_size;

	n2->content = tmp_c;
	n2->content_size = tmp_cs;
}
