/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 00:10:22 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:36:34 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*c1;
	unsigned const char		*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (n > 0)
	{
		while (n)
		{
			if (*c1 != *c2)
				return (*c1 - *c2);
			c1++;
			c2++;
			n--;
		}
	}
	return (0);
}
