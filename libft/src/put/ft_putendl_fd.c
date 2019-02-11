/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:10:32 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:36:45 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, str + i, 1);
		i++;
	}
	write(fd, "\n", 1);
}
