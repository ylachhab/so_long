/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:17:39 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/14 19:08:38 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(t_long *data)
{
	int	i;

	i = 0;
	while (i < data->y)
	{
		if (data->map[i][0] != '1' || data->map[i][data->x - 1] != '1')
		{
			ft_putstr("you should be closed the map with the walls\n");
			exit_error(data);
		}
		i++;
	}
	i = 0;
	while (i < data->x)
	{
		if (data->map[0][i] != '1' || data->map[data->y - 1][i] != '1')
		{
			ft_putstr("you should be closed the map with the wall\n");
			exit_error(data);
		}
		i++;
	}
}

int	checkmap(char c)
{
	if (c == 'P' || c == 'C' || c == '1' || c == '0' || c == 'E')
		return (1);
	return (0);
}

void	afficherror(t_long *data)
{
	ft_putstr("error :(\n");
	exit_error(data);
}

void	m_map(t_long *data)
{
	int	j;
	int	i;

	i = 0;
	while (i < data->y)
	{
		j = 0;
		while (data->map[i][j] && j < data->x)
		{
			if (checkmap(data->map[i][j]))
			{
				if (data->map[i][j] == 'P')
					data->player++;
				else if (data->map[i][j] == 'E')
					data->exit++;
				else if (data->map[i][j] == 'C')
					data->collect++;
				j++;
			}
			else
				afficherror(data);
		}
		i++;
	}
}

void	containmap(t_long *data)
{
	if (data->player > 1)
	{
		ft_putstr("Multiplayer mode unavailable\n");
		exit_error(data);
	}
	if (data->player < 1)
	{
		ft_putstr("You must set a player 'P'\n");
		exit_error(data);
	}
	if (data->exit > 1)
	{
		ft_putstr("Only 1 exit is permitted\n");
		exit_error(data);
	}
	if (data->exit < 1)
	{
		ft_putstr("You must set an exit 'E'\n");
		exit_error(data);
	}
	if (data->collect < 1)
	{
		ft_putstr("You must set a collectible 'C'\n");
		exit_error(data);
	}
}
