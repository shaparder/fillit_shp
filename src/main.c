/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:38:50 by osfally           #+#    #+#             */
/*   Updated: 2019/02/09 15:04:13 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Entry point for the program, if more than 1 argument, return the proper usage info.
*/

#include "../libft_shp/libft.h"
#include "../includes/fillit.h"
#include <fcntl.h>

void	print_map(t_map *map)
{

}

t_map	solve_tetris(t_list list)
{

}

t_list	*read_tetris(int fd)
{

}

int		main(int argc, char **argv)
{
	t_list		*tetriminos_list;
	t_map		*map;
	int			fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		return(1);
	}
	if ((list = read_tetris(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("file error.");
		return (1);
	}
	map = solve_tetris(tetriminos_list);
	print_map(map);
	free(map);
	free(tetriminos_list);
	return (0);
}
