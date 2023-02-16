/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:23:20 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/16 02:03:21 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	checkfile(char *str)
{
	int	i;
	int	fd;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.' && str[i - 4])
		return (1);
	else
	{
		ft_putstr("error files without .ber extension is not accepted\n");
		return (0);
	}
	close(fd);
}

void	map_newline(t_long *data)
{
	if (data->map[data->y - 1][data->x] == '\n')
	{
		ft_printf("error in the end of file --\n");
		exit_error(data);
	}
}

void	rectangularmap(t_long *data, char *str)
{
	int		fd;
	char	*line;

	fd = ft_open(str);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->x = my_strlen(line);
		if (!data->oldx)
			data->oldx = data->x;
		if (data->oldx != data->x)
		{
			ft_putstr("error map isn't rectangular+++\n");
			exit_error(data);
		}
		if (data->x == data->y)
		{
			ft_putstr("error map isn't rectangular--\n");
			exit_error(data);
		}
		free(line);
	}
	close(fd);
}

void	ft_parsing(t_long *data, char *str)
{
	ft_initialize_var(data);
	mallocmap(data, str);
	stockmap(data, str);
	rectangularmap(data, str);
	map_newline(data);
	valid_map(data);
	m_map(data);
	containmap(data);
	position_player(data);
	changep(data, str);
}
