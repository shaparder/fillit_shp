/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:05:51 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:36:51 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putstr_fd(char const *str, int fd)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, str + i, 1);
		i++;
	}
}
