/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:45:55 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/14 09:21:32 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right_d(t_long *data, int keycode)
{
	if (keycode == 2)
	{
		if (data->map[data->ypl][data->xpl + 1] == 'E' && data->collect == 0)
			ft_destroy(data);
		if (data->map[data->ypl][data->xpl + 1] == '0'
			&& data->map[data->ypl][data->xpl + 1] != '1')
		{
			data->map[data->ypl][data->xpl] = '0';
			data->map[data->ypl][data->xpl + 1] = 'P';
			data->xpl++;
			ft_draw(data);
		}
		if (data->map[data->ypl][data->xpl + 1] == 'C' && data->collect > 0)
		{
			data->collect--;
			data->map[data->ypl][data->xpl] = '0';
			data->map[data->ypl][data->xpl + 1] = 'P';
			data->xpl++;
			ft_draw(data);
		}
	}
}

void	ft_left_a(t_long *data, int keycode)
{
	if (keycode == 0)
	{
		if (data->map[data->ypl][data->xpl - 1] == 'E' && data->collect == 0)
			ft_destroy(data);
		if (data->map[data->ypl][data->xpl - 1] == '0'
			&& data->map[data->ypl][data->xpl - 1] != '1')
		{
			data->map[data->ypl][data->xpl] = '0';
			data->map[data->ypl][data->xpl - 1] = 'P';
			data->xpl--;
			ft_draw(data);
		}
		if (data->map[data->ypl][data->xpl - 1] == 'C' && data->collect > 0)
		{
			data->collect--;
			data->map[data->ypl][data->xpl] = '0';
			data->map[data->ypl][data->xpl - 1] = 'P';
			data->xpl--;
			ft_draw(data);
		}
	}
}

void	ft_down_s(t_long	*data, int keycode)
{
	if (keycode == 1)
	{
		if (data->map[data->ypl + 1][data->xpl] == 'E' && data->collect == 0)
			ft_destroy(data);
		if (data->map[data->ypl + 1][data->xpl] == '0'
			&& data->map[data->ypl + 1][data->xpl] != '1')
		{
			data->map[data->ypl][data->xpl] = '0';
			data->map[data->ypl + 1][data->xpl] = 'P';
			data->ypl++;
			ft_draw(data);
		}
		if (data->map[data->ypl + 1][data->xpl] == 'C'
			&& data->map[data->ypl + 1][data->xpl] != '1')
		{
			data->collect--;
			data->map[data->ypl][data->xpl] = '0';
			data->map[data->ypl + 1][data->xpl] = 'P';
			data->ypl++;
			ft_draw(data);
		}
	}
}

void	ft_up_w(t_long	*data, int keycode)
{
	if (keycode == 13)
	{
		if (data->map[data->ypl - 1][data->xpl] == 'E' && data->collect == 0)
			ft_destroy(data);
		if (data->map[data->ypl - 1][data->xpl] == '0'
			&& data->map[data->ypl - 1][data->xpl] != '1')
		{
			data->map[data->ypl][data->xpl] = '0';
			data->map[data->ypl - 1][data->xpl] = 'P';
			data->ypl--;
			ft_draw(data);
		}
		if (data->map[data->ypl - 1][data->xpl] == 'C'
			&& data->map[data->ypl - 1][data->xpl] != '1')
		{
			data->collect--;
			data->map[data->ypl][data->xpl] = '0';
			data->map[data->ypl - 1][data->xpl] = 'P';
			data->ypl--;
			ft_draw(data);
		}
	}
}
