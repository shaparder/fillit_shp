/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:01:25 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:36:31 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*cdst;
	const unsigned char	*csrc;

	if (len == 0 || dst == src)
		return (dst);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	if (csrc < cdst)
		while (len--)
			cdst[len] = csrc[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
