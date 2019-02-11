/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:42:55 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:41:02 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (ISWP(s[i]))
		i++;
	x = i;
	while (s[i + 1])
		i++;
	while (ISWP(s[i]))
		i--;
	MACH(str = (char *)malloc(sizeof(char) * (i - x + 2)), NULL);
	while (x <= i)
	{
		str[j] = s[x];
		j++;
		x++;
	}
	str[j] = '\0';
	return (str);
}
