/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:14:52 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:41:02 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;

	i = ft_strlen(str);
	if (ch == '\0')
		return ((char *)(str + i));
	while (i >= 0)
	{
		if (str[i] == (char)ch)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}
