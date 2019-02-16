/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:38:50 by osfally           #+#    #+#             */
/*   Updated: 2019/02/15 20:06:15 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fillit.h"
#include <fcntl.h>
#include <stdio.h>

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
int				solve_map(t_map *map, t_list *list, char letter)
{
	int			y;
	int			x;

	if (list == NULL)
		return (1);
			int *tetripos = list->content;
			printf("tetripos to check = %i%i%i%i\n\n", tetripos[0], tetripos[1], tetripos[2], tetripos[3]);
	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (check_tetri(map->array, y, x, list->content, map->size, letter) == 1)
			{
					printf("New tetris in map:\n");
					print_map(map);
					printf("\n");
				if (solve_map(map, list->next, ++letter))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

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
	printf("--------------------------------------\n\n");
	printf("Map size = %i\n\n", map->size);
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

// Gives rounded down suare root of argument.
int				rounded_sqrt(int x)
{
	int			i;

	i = 1;
	while (i * i < x)
		i++;
	return (i);
}

// Tries to find solution for map
t_map			*find_solution(t_list *list)
{
	t_map		*map;
	int			size;
	char		start_letter;

	size = rounded_sqrt(ft_lstcount(list) * 4);
	map = create_map(size);
			printf("The empty map:\n");
			print_map(map);
			printf("\n");
	start_letter = 'A';
	while (solve_map(map, list, start_letter) == 0 && size < 6)
	{
		size++;
		free_map(map);
		map = create_map(size);
				printf("The empty map:\n");
				print_map(map);
				printf("\n");
	}
	return (map);
}


// Free the tetriminos structure.
/* void			free_tetriminos(t_etriminos *tetriminos)
{
	ft_memdel((void **)(&(tetriminos->pos)));
	ft_memdel((void **)(&(tetriminos)));
} */

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

// Store the positions of the blocks of the tetriminos in an int array, and puts it top left of the "map".
int				*get_pos(char *buf)
{
	int			*pos;
	int			i;
	int			j;
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
	return (pos);
}

// Create new tetriminos struct with set data(letter and position).
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


// Check connections of each block.
int					check_connections(char *buf)
{
	int			connections;
	int			i;

	i = 0;
	connections = 0;
	while (buf[i])
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
	printf("connections = %i / ", connections);
	if (connections != 6 && connections != 8)
		return (1);
	else
		return (0);
}


// Check if the file is in the good format.
int					valid_format(char *buf, int count)
{
	int			i;
	int			bloks;

	i = 0;
	bloks = 0;
	while (i < 20)
	{
		if (i % 5 != 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
			{
				return (1);
				printf("bad character in source_file\n\n");
			}

			else if (buf[i] == '#' && ++bloks > 4)
			{
				return (2);
				printf("too much blocks tetriminos in source_file\n\n");
			}
		}
		else if (buf[i] != '\n')
		{
			return (3);
			printf("$ not correctly placed\n\n");
		}
		i++;
	}
	if (count == 21 && buf[20] != '\n')
	{
		return (4);
		printf("$ bad ending of tetriminos format\n\n");
	}
	if (check_connections(buf))
	{
		return (5);
		printf("tetriminos not connected\n\n");
	}
	return (0);
}




void printList(t_list *head)
{
    t_list *temp = head;
	int	*tetripos;
	int	i = 0;
	printf("List print: \n\n");
    while(temp != NULL)
    {
		printf("node number %i \n", i);
		tetripos = temp->content;
		printf("tetripos = %i%i%i%i\n\n", tetripos[0], tetripos[1], tetripos[2], tetripos[3]);
        temp = temp->next;
		i++;
    }
}





// Reads the file descriptor and put all the tetriminos in a linked list.
t_list				*read_file(int fd)
{
	int			count;
	char		letter;
	char		*buf;
	t_list		*tetrilist;
	int			*tetripos;

	tetrilist = NULL;
	buf = ft_strnew(21);
	letter = 'A';
	printf("tetriminos reading...\n\n");
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (valid_format(buf, count) != 0 || (tetripos = get_pos(buf)) == NULL)
		{
			ft_memdel((void **)&buf);
			close(fd);
			return (free_list(tetrilist));
		}
		printf("tetripos = %i%i%i%i\n\n", tetripos[0], tetripos[1], tetripos[2], tetripos[3]);
		ft_lstadd(&tetrilist, ft_lstnew(tetripos, (sizeof(int) * 4)));
	}
	printList(tetrilist);
	close(fd);
	return (tetrilist);
}

/*
** Entry point for the program.
** If more than 1 argument, return the proper usage info.
*/
int					main(int argc, char **argv)
{
	t_list		*tetrilist;
	t_map		*map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		return (1);
	}
	printf("existing file\n\n");
	if ((tetrilist = read_file(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("invalid file.");
		return (1);
	}
	map = find_solution(tetrilist);
	print_map(map);
	free(map);
	free_list(tetrilist);
	return (0);
}
