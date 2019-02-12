/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:03:57 by osfally           #+#    #+#             */
/*   Updated: 2019/02/11 20:04:31 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
**	Find the maximum of an integer array
*/

int		findmax(int *array, int array_size)
{
	int		max;

	array_size--;
	max = array[array_size];
	while (array_size >= 0)
	{
		if (array[array_size] > max)
		{
			max = array[array_size];
		}
		array_size--;
	}
	return (max);
}
