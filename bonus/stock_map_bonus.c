/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:27:33 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/14 16:39:11 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_error(t_long *data)
{
	int	i;

	i = 0;
	while (i < data->y)
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	if (data->map)
	{
		free(data->map);
		data->map = NULL;
	}
	ft_printf("-----error-----\n");
	exit(1);
}

void	mallocmap(t_long *data, char *str)
{
	int		fd;
	char	*line;

	if (checkfile(str) == 0)
		exit_error(data);
	fd = ft_open(str);
	line = get_next_line(fd);
	data->x = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->y++;
	}
	close(fd);
	data->map = (char **)malloc(sizeof(char *) * data->y + 1);
	if (!data->map)
		exit_error(data);
}

void	stockmap(t_long *data, char *s)
{
	int		j;
	int		k;
	int		fd;
	char	*line;

	j = 0;
	fd = ft_open(s);
	while (1)
	{
		k = 0;
		line = get_next_line(fd);
		if (line == 0)
			break ;
		data->map[j] = ft_strdup(line);
		free(line);
		j++;
	}
	data->map[j] = NULL;
	close (fd);
}
