/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:51:40 by osfally           #+#    #+#             */
/*   Updated: 2019/02/22 23:50:05 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# include <fcntl.h>

typedef struct		s_map
{
		int			size;
		char		**array;
}					t_map;


t_list			*read_file(int fd);
int				valid_format(char *buf, int count);
int				check_connections(char *buf);
int				*get_pos(char *buf);
t_list			*file_error(char *buf, t_list *tetrilist, int fd);
t_map			*map_solver(t_list *list);
int				map_filler(t_map *map, t_list *list, char letter);
int				check_tetri(char **array, int y, int x, int *tetripos, int size, char letter);
void			set_tetri(char **array, int y, int x, int *tetripos, char letter);
t_map			*create_map(int size);
void			free_map(t_map *map);
void			print_map(t_map *map);
t_list			*free_list(t_list *tetrilist);

#endif
