/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:51:40 by osfally           #+#    #+#             */
/*   Updated: 2019/02/09 14:09:21 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_etriminos
{
		char		letter;
		char		**pos;
}					t_etriminos;

typedef struct		s_map
{
		int			size;
		char		**array;
}					t_map;

#endif
