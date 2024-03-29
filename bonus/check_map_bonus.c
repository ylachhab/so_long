/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:17:39 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/17 04:59:54 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (c == 'P' || c == 'C' || c == '1' || c == '0' || c == 'E' || c == 'V')
		return (1);
	return (0);
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
				ft_counter(data, data->map[i][j]);
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
		exit_error(data);
	if (data->player < 1)
		exit_error(data);
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
	if (data->enemy < 1)
	{
		ft_putstr("You must set a enemy 'V'\n");
		exit_error(data);
	}
}
