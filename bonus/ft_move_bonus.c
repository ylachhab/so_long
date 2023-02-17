/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:09:45 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/17 04:46:56 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy(t_long	*data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->animation);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->grass);
	mlx_destroy_image(data->mlx_ptr, data->girl);
	mlx_destroy_image(data->mlx_ptr, data->exi);
	mlx_destroy_image(data->mlx_ptr, data->appel);
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
	exit (0);
}

void	ft_right(t_long *data, int keycode)
{
	if (keycode == 124)
	{
		if (data->map[data->ypl][data->xpl + 1] == 'V')
			ft_destroy(data);
		else if (data->map[data->ypl][data->xpl + 1] == 'E'
		&& data->collect == 0)
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

void	ft_left(t_long *data, int keycode)
{
	if (keycode == 123)
	{
		if (data->map[data->ypl][data->xpl - 1] == 'V')
			ft_destroy(data);
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

void	ft_down(t_long	*data, int keycode)
{
	if (keycode == 125)
	{
		if (data->map[data->ypl + 1][data->xpl] == 'V')
			ft_destroy(data);
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

void	ft_up(t_long	*data, int keycode)
{
	if (keycode == 126)
	{
		if (data->map[data->ypl - 1][data->xpl] == 'V')
			ft_destroy(data);
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
