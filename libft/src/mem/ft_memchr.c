/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:18:01 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:36:36 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*ss;
	size_t			i;

	i = 0;
	ss = (unsigned char *)s;
	while (i < len)
	{
		if ((*ss) == ((unsigned char)c))
			return (ss);
		i++;
		ss++;
	}
	return (NULL);
}
