/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:41:51 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:41:02 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (substr[0] == '\0')
		return ((char *)str);
	while (str[x])
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
