/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:17:54 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:41:02 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (substr[0] == '\0')
		return ((char *)str);
	while (str[x] && x < len)
	{
		if (str[x] == substr[y])
			y++;
		else
		{
			x -= y;
			y = 0;
		}
		if (substr[y] == '\0')
			return ((char *)(str + x - y + 1));
		x++;
	}
	return (NULL);
}
