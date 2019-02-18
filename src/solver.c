/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:58:37 by osfally           #+#    #+#             */
/*   Updated: 2019/02/17 19:11:54 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

//	Set tetriminos in the array at pos [y][x].
void			set_tetri(char **array, int y, int x, int *tetripos, char letter)
{
	int			i;
	int			t;
	int			tp;

	i = 0;
	tp = -1;
	while (i < 4)
	{
		if (i > 0)
			tp = tetripos[i - 1];
		t = tetripos[i];
		if (tp < t)
			array[y][x + t] = letter;
		else if (tp >= t)
			array[++y][x + t] = letter;
		i++;
	}
}

// Check if tetris fits in position array[y][x]. Because of the storing being a 1d array, needs to use if/else if.
int				check_tetri(char **array, int y, int x, int *tetripos, int size, char letter)
{
	int			i;
	int			t;
	int			tp;
	int			yy;


	i = 0;
	tp = -1;
	yy = y;
	while (i < 4)
	{
		if (i > 0)
			tp = tetripos[i - 1];
		t = tetripos[i];
		if (tp < t && ((x + t > size) || (array[yy][x + t] != '.')))
				return (0);
		else if (tp >= t && ((x + t > size) || ++yy >= size ||(array[yy][x + t] != '.')))
				return (0);
		i++;
	}
	set_tetri(array, y, x, tetripos, letter);
	return (1);
}

// BACKTRACKING FUNCTION ->recursion call if tetris is placed, end success if no next node in list.
int				map_filler(t_map *map, t_list *list, char letter)
{
	int			y;
	int			x;

	if (list == NULL)
		return (1);
	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (check_tetri(map->array, y, x, list->content, map->size, letter) == 1)
			{
				if (map_filler(map, list->next, ++letter))
					return (1);
				else
					set_tetri(map->array, y, x, list->content, '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

// Tries to find solution for map
t_map			*map_solver(t_list *list)
{
	t_map		*map;
	int			lst_size;
	int			size;
	char		start_letter;

	lst_size = (ft_lstcount(list) * 4);
	size = 1;
	while (size * size < lst_size)
		size++;
	map = create_map(size);
	start_letter = 'A';
	while (map_filler(map, list, start_letter) == 0)
	{
		size++;
		free_map(map);
		map = create_map(size);
	}
	return (map);
}
