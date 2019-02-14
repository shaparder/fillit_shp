/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:38:50 by osfally           #+#    #+#             */
/*   Updated: 2019/02/13 22:04:37 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fillit.h"
#include <fcntl.h>
#include <stdio.h>


/* void print_solution(t_map *map)
{
} */

/*
**
*/

t_map			*create_map(int size)
{
	t_map	*map;

	return (map);
}

/*
** Tries to find solution for map
*/

t_map			*find_solution(t_list *list)
{
	t_map	*map;
	int		size;

	size = ft_lstcount(list);
	map = create_map(size);
	while(solve_map())
	{
		size++;
		free_map(map);
		map = create_map(size);
	}
	return (map);
}

/*
** Free the tetriminos structure.
*/

/* void			free_tetriminos(t_etriminos *tetriminos)
{
	ft_memdel((void **)(&(tetriminos->pos)));
	ft_memdel((void **)(&(tetriminos)));
} */

/*
** Free the list structure.
*/

t_list			*free_list(t_list *tetriminos_list)
{
	t_list	*next;
	int		*tetripos;

	while (tetriminos_list)
	{
		tetripos = tetriminos_list->content;
		next = tetriminos_list->next;
		free((void **)(tetripos));
		free((void **)tetriminos_list);
		tetriminos_list = next;
	}
	return (NULL);
}

/*
** Store the positions of the blocks of the tetriminos in an int array, and puts it top left of the "map".
*/

int				*get_pos(char *buf)
{
	int			*pos;
	int			i;
	int 		j;
	int			k;
	int			min;

	i = 0;
	j = 0;
	k = 0;
	pos = (int *)malloc(sizeof(int) * 4);
	while (buf[i])
	{
		if (buf[i] == '#')
			pos[k++] = j;
		i++;
		j < 4 ? (j++) : (j = 0);
	}
	if ((min = findmin(pos, 4)) != 0)
		while (min-- > 0 && ((k = 4) != 0))
			while (k > 0)
				pos[--k]--;
	return(pos);
}

/*
** Create new tetriminos struct with set data(letter and position).
*/

/* t_etriminos		*create_tetriminos(char letter, char *buf)
{
	t_etriminos *tetriminos;

	tetriminos = (t_etriminos *)malloc(sizeof(t_etriminos));
	tetriminos->letter = letter;
	printf("tetriletter = %c\n", letter);
	tetriminos->pos = get_pos(buf);
	printf("tetriminos->pos = %i%i%i%i\n\n", tetriminos->pos[0],
		tetriminos->pos[1], tetriminos->pos[2], tetriminos->pos[3]);
	return(tetriminos);
} */

/*
** Check connections of each block
*/

int				check_connections(char *buf)
{
	int		connections;
	int		i;

	i = 0;
	connections = 0;
	while(buf[i])
	{
		if (buf[i] == '#')
		{
			if (i <= 13 && buf[i + 5] == '#')
				connections++;
			if (i >= 5 && buf[i - 5] == '#')
				connections++;
			if (i <= 17 && buf[i + 1] == '#')
				connections++;
			if (i >= 1 && buf[i - 1] == '#')
				connections++;
		}
		i++;
	}
	if (connections != 6 && connections != 8)
		return (1);
	else
		return (0);
}

/*
** Check if the file is in the good format.
*/

int				valid_format(char *buf, int count)
{
	int		i;
	int		bloks;

	i = 0;
	bloks = 0;
	while (i < 20)
	{
		if (i % 5 != 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (1);
			else if (buf[i] == '#' && ++bloks > 4)
				return (2);
		}
		else if (buf[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && buf[20] != '\n')
		return (4);
	if (check_connections(buf))
		return (5);
	return (0);
}

/*
** Reads the file descriptor and put all the tetriminos in a linked list.
*/

t_list			*read_file(int fd)
{
	int			count;
	char		letter;
	char		*buf;
	t_list		*tetriminos_list;
	int			*tetripos;

	tetriminos_list = NULL;
	buf = ft_strnew(21);
	letter = 'A';
	printf("tetriminos reading...\n\n");
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (valid_format(buf, count) != 0 || (tetripos = get_pos(buf)) == NULL)
		{
			ft_memdel((void **)&buf);
			close(fd);
			return (free_list(tetriminos_list));
		}
		printf("tetripos = %i%i%i%i\n\n", tetripos[0], tetripos[1], tetripos[2], tetripos[3]);
		ft_lstadd(&tetriminos_list, ft_lstnew(tetripos, sizeof(tetripos)));
	}
	ft_lstrev(&tetriminos_list);
	close(fd);
	return (tetriminos_list);
}

/*
** Entry point for the program.
** If more than 1 argument, return the proper usage info.
*/

int				main(int argc, char **argv)
{
	t_list		*tetriminos_list;
	t_map		*map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		return (1);
	}
	printf("existing file\n\n");
	if ((tetriminos_list = read_file(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("invalid file.");
		return (1);
	}
	map = find_solution(tetriminos_list);
	// print_solution(square);
	free(map);
	free_list(tetriminos_list);
	return (0);
}
