/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_utils_bonus3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:05:30 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/21 00:55:10 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	pose_player(t_long *data)
{
	int	i;
	int	j;

	i = rand() % 3 - 1;
	j = rand() % 3 - 1;
	if (data->map[data->yv][data->xv + 1] == 'P' && i == 1)
		ft_destroy(data);
	else if (data->map[data->yv][data->xv - 1] == 'P' && i == -1)
		ft_destroy(data);
	else if (data->map[data->yv + 1][data->xv] == 'P' && j == 1)
		ft_destroy(data);
	else if (data->map[data->yv - 1][data->xv] == 'P' && j == -1)
		ft_destroy(data);
}

void	right_enemy(t_long *data)
{
	data->map[data->yv][data->xv] = '0';
	data->map[data->yv][++(data->xv)] = 'V';
}

void	ft_animation_enemy(t_long *data)
{
	int	i;
	int	j;

	i = rand() % 3 - 1;
	j = rand() % 3 - 1;
	pose_player(data);
	if (data->map[data->yv][data->xv + 1] == '0' && i == 1)
		right_enemy(data);
	else if (data->map[data->yv][data->xv - 1] == '0' && i == -1)
	{
		data->map[data->yv][data->xv] = '0';
		data->map[data->yv][--(data->xv)] = 'V';
	}
	else if (data->map[data->yv + 1][data->xv] == '0' && j == 1)
	{
		data->map[data->yv][data->xv] = '0';
		data->map[++(data->yv)][data->xv] = 'V';
	}
	else if (data->map[data->yv - 1][data->xv] == '0' && j == -1)
	{
		data->map[data->yv][data->xv] = '0';
		data->map[--(data->yv)][data->xv] = 'V';
	}
	ft_draw(data);
}
