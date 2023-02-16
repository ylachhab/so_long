/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:18:24 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/15 09:04:58 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_long *data, int y, int x)
{
	if (y < 0 || y >= data->y || x < 0 || x >= data->x
		|| data->map[y][x] == 'X' || data->map[y][x] == '1'
		|| data->map[y][x] == 'E')
		return ;
	data->map[y][x] = 'X';
	flood_fill(data, y, x - 1);
	flood_fill(data, y, x + 1);
	flood_fill(data, y - 1, x);
	flood_fill(data, y + 1, x);
}

void	ft_print_error(t_long *data)
{
	ft_putstr("Error you don't have valid path in the map\n");
	exit_error(data);
}

void	ft_check_error(t_long *data)
{
	int	i;
	int	j;

	i = 0;
	flood_fill(data, data->ypl, data->xpl);
	while (i < data->y)
	{
		j = 0;
		while (data->map[i][j] && j < data->x)
		{
			if (data->map[i][j] == 'C')
				ft_print_error(data);
			if (data->map[i][j] == 'E' && (data->map[i][j + 1] != 'X'
				&& data->map[i][j - 1] != 'X' && data->map[i + 1][j] != 'X'
				&& data->map[i - 1][j] != 'X'))
				ft_print_error(data);
			j++;
		}
		i++;
	}
}

void	changep(t_long *data, char *s)
{
	int	i;

	flood_fill(data, data->ypl, data->xpl);
	ft_check_error(data);
	i = 0;
	while (i < data->y)
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	stockmap(data, s);
}
