/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:38:50 by osfally           #+#    #+#             */
/*   Updated: 2019/02/11 22:27:23 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fillit.h"
#include <fcntl.h>
#include <stdio.h>


/* void print_solution(t_map *map)
{
} */

/* t_map *solve_tetris(t_list *list)
{
} */

/*
** Free the tetriminos structure.
*/

void			free_tetriminos(t_etriminos *tetriminos)
{
	ft_memdel((void **)(&(tetriminos->pos)));
	//ft_memdel((void **)(&(tetriminos->letter)));
	//ft_memdel((void **)tetriminos);
}

/*
** Free the list structure.
*/

t_list			*free_list(t_list *list)
{
	t_etriminos	*tetriminos;
	t_list	*next;

	while (list)
	{
		tetriminos = list->content;
		next = list->next;
		free_tetriminos(tetriminos);
		ft_memdel((void **)list);
		list = next;
	}
	return (NULL);
}

/*
**	Store the positions of the blocks of the tetriminos in an int array, and puts it top left of the "map".
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
	for(size_t g = 0; g < 4; g++)
	{
		printf("%i", pos[g]);
	}
	printf("\n");
	return(pos);
}

/*
** Create new tetriminos struct with set data(letter and position).
*/

t_etriminos		*create_tetriminos(char letter, char *buf)
{
	t_etriminos *tetriminos;

	tetriminos = (t_etriminos *)malloc(sizeof(t_etriminos));
	tetriminos->letter = letter;
	printf("tetriletter = %c\n", letter);
	tetriminos->pos = get_pos(buf);
	return(tetriminos);
}

/*
** Reads the file descriptor and put all the tetriminos in a linked list.
*/

t_list			*read_file(int fd)
{
	int			count;
	char		letter;
	char		*buf;
	t_list		*list;
	t_etriminos	*tetriminos;

	list = NULL;
	buf = ft_strnew(21);
	letter = 'A';
	printf("tetriminos reading...\n\n");
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if ((tetriminos = create_tetriminos(letter++, buf)) == NULL)
		{
			ft_memdel((void **)&buf);
			close(fd);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetriminos, sizeof(t_etriminos)));
		//ft_memdel((void **)&tetriminos);
	}
	ft_lstrev(&list);
	close(fd);
	return (list);
}

/*
** Entry point for the program.
** If more than 1 argument, return the proper usage info.
*/

int				main(int argc, char **argv)
{
	t_list		*tetriminos_list;
	// t_map		*square;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		return (1);
	}
	printf("valid file\n\n");
	if ((tetriminos_list = read_file(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("invalid file.");
		return (1);
	}
	// square = solve_tetris(tetriminos_list);
	// print_solution(square);
	// free(square);
	free_list(tetriminos_list);
	return (0);
}
