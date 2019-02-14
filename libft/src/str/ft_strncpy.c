/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:21:02 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:41:02 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t len)
{
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen((char *)s2);
	while (i < len)
	{
		if (i <= slen)
			s1[i] = s2[i];
		else
			s1[i] = '\0';
		i++;
	}
	return (s1);
}
