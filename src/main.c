/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:38:50 by osfally           #+#    #+#             */
/*   Updated: 2019/02/17 20:09:50 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Entry point for the program.
** If more than 1 argument, return the proper usage info.
*/
int				main(int argc, char **argv)
{
	t_list		*tetrilist;
	t_map		*map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		return (1);
	}
	if ((tetrilist = read_file(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = map_solver(tetrilist);
	print_map(map);
	free_map(map);
	free_list(tetrilist);
	return (0);
}
