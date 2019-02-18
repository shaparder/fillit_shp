/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:56:44 by osfally           #+#    #+#             */
/*   Updated: 2019/02/17 20:05:58 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

// Check connections of each block.
int				check_connections(char *buf)
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
	if (connections != 6 && connections != 8)
		return (1);
	else
		return (0);
}


// Check if the file is in the good format.
int				valid_format(char *buf, int count)
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
	if (count != 21 && count != 20)
		return (6);
	return (0);
}

// Reads the file descriptor and put all the tetriminos in a linked list.
t_list			*read_file(int fd)
{
	int			count;
	char		letter;
	char		*buf;
	t_list		*tetrilist;
	int			*tetripos;

	tetrilist = NULL;
	buf = ft_strnew(21);
	letter = 'A';
	while ((count = read(fd, buf, 21)))
	{
		if (valid_format(buf, count) != 0 || (tetripos = get_pos(buf)) == NULL)
		{
			ft_memdel((void **)&buf);
			close(fd);
			return (free_list(tetrilist));
		}
		ft_lstadd(&tetrilist, ft_lstnew(tetripos, (sizeof(int) * 4)));
		ft_memdel((void **)&tetripos);
	}
	ft_memdel((void **)&buf);
	ft_lstrev(&tetrilist);
	close(fd);
	return (tetrilist);
}

