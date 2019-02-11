/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 00:27:55 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:41:02 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	i = ft_strlen(s1);
	if (!(cpy = (char *)malloc(sizeof(*cpy) * (i + 1))))
		return (NULL);
	cpy[i] = '\0';
	while (i--)
		cpy[i] = s1[i];
	return (cpy);
}
