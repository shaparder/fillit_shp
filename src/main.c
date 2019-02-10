/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:38:50 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 09:17:51 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_shp/libft.h"
#include "../includes/fillit.h"
#include <fcntl.h>

void print_square(t_map *map)
{
}

t_map *solve_tetris(t_list *list)
{
}

/*
**	Store the positions of the blocks of the tetriminos in an int array.
*/

int		*get_pos(char *buf)
{
	int			*pos;
	int			i;
	int 		j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			pos[k++] = j;
		i++;
		j < 4 ? (j++) : (j = 0);
	}
	return(pos);
}

/*
** Reads the file descriptor and put all the tetriminos in a linked list.
*/

t_list *read_tetris(int fd)
{
	int			count;
	char		letter;
	char		*buf;
	t_list		*list;
	t_etriminos	*pute;

	list = NULL;
	buf = ft_strnew(21);
	letter = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		pute->letter = letter++;
		pute->pos = get_pos(buf);
		ft_lstadd(&list, ft_lstnew(pute, sizeof(t_etriminos)));
		ft_bzero(buf, 21);
	}
	ft_lstrev(&list);
	close(fd);
	return (list);
}

/*
** Entry point for the program
** store tetriminos into a list / tries to fit them into the smallest square possible / print the square solved
** if more than 1 argument, return the proper usage info.
*/

int main(int argc, char **argv)
{
	t_list		*tetriminos_list;
	t_map		*square;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		return (1);
	}
	if ((tetriminos_list = read_tetris(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("invalid file.");
		return (1);
	}
	square = solve_tetris(tetriminos_list);
	print_square(square);
	free(square);
	free(tetriminos_list);
	return (0);
}
