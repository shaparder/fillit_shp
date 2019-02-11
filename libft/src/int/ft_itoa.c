/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:26 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:05:51 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	nlen(int n)
{
	int len;

	len = (n <= 0 ? 1 : 0);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*str;
	int				negative;
	int				len;

	negative = (n < 0 ? 1 : 0);
	len = nlen(n);
	MACH(str = (char *)malloc(sizeof(char) * (len + 1)), NULL);
	nbr = (n < 0 ? -n : n);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
