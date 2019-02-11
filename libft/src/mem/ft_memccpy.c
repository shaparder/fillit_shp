/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:01:18 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:36:37 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t				i;
	unsigned char		*cdst;
	unsigned char		*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == ((unsigned char)c))
			return ((dst + i + 1));
		i++;
	}
	return (NULL);
}
