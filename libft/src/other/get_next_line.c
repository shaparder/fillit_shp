/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:14:39 by osfally           #+#    #+#             */
/*   Updated: 2019/02/10 11:36:29 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int			get_line(char **line, char *str)
{
	size_t			i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	*line = ft_strsub(str, 0, i);
	return (i);
}

static char			*stock_line(char *str, size_t i)
{
	char			*tmp;
	size_t			j;

	tmp = ft_strnew(ft_strlen(str) - i);
	j = 0;
	while (str[i + j])
	{
		tmp[j] = str[i + j];
		j++;
	}
	tmp[j] = '\0';
	ft_strdel(&str);
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*str_arr[MAX_FD];
	char			*tmp;
	int				ret;
	size_t			i;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	(!str_arr[fd]) ? str_arr[fd] = ft_strnew(1) : 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(str_arr[fd], buff);
		free(str_arr[fd]);
		str_arr[fd] = tmp;
		if (ft_strchr(str_arr[fd], '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(str_arr[fd]))
		return (0);
	i = get_line(line, str_arr[fd]);
	(i < ft_strlen(str_arr[fd])) ? str_arr[fd] = stock_line(str_arr[fd], i + 1)
		: ft_bzero(str_arr[fd], ft_strlen(str_arr[fd]));
	return (1);
}
