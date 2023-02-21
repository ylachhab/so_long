/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:42:52 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/21 00:40:24 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	position_player(t_long *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data->y)
	{
		j = 0;
		while (data->map[i] && j < data->x)
		{
			if (data->map[i][j] == 'P')
			{
				data->xpl = j;
				data->ypl = i;
			}
			j++;
		}
		i++;
	}
}

void	position_enemy(t_long *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'V' && data->enemy > 0)
			{
				data->xv = j++;
				data->yv = i++;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	draw_anim(t_long *data, int pos)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'V' && data->enemy > 0)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->animation[pos], j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
