/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:58:42 by osfally           #+#    #+#             */
/*   Updated: 2019/02/17 19:12:36 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

// Print the map (2d array in map struct)
void			print_map(t_map *map)
{
	int			i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}


// Free a map structure.
void			free_map(t_map *map)
{
	int			i;

	i = 0;
	while (i < map->size)
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
	free(map);
}


// Create a map struct with a size and an allocated **array.
t_map			*create_map(int size)
{
	t_map		*map;
	int			i;
	int			j;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)malloc(sizeof(char *) * size);
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

//Free the list structure.
t_list			*free_list(t_list *tetrilist)
{
	t_list		*next;
	int			*tetripos;

	while (tetrilist)
	{
		tetripos = tetrilist->content;
		next = tetrilist->next;
		free((void **)(tetripos));
		free((void **)tetrilist);
		tetrilist = next;
	}
	return (NULL);
}
