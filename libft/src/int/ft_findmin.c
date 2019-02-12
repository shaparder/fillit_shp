/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:03:57 by osfally           #+#    #+#             */
/*   Updated: 2019/02/11 19:40:37 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
**	Find the minimum of an integer array
*/

int		findmin(int *array, int array_size)
{
	int		min;

	array_size--;
	min = array[array_size];
	while (array_size >= 0)
	{
		if (array[array_size] < min)
		{
			min = array[array_size];
		}
		array_size--;
	}
	return (min);
}
