/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:34:23 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:04:50 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_atoi(char *str)
{
	int					sign;
	unsigned long int	nb;

	nb = 0;
	sign = 1;
	while ((*str == ' ') || ((*str >= 9) && (*str <= 13)))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str >= '0') && (*str <= '9') && (*str != '\0'))
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (sign * nb);
}
