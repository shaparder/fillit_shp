/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:51:40 by osfally           #+#    #+#             */
/*   Updated: 2019/02/11 14:39:53 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"

typedef struct		s_etriminos
{
		char		letter;
		int			*pos;
}					t_etriminos;

typedef struct		s_map
{
		int			size;
		char		**array;
}					t_map;

t_list *read_file(int fd);
int		*get_pos(char *buf);


#endif
