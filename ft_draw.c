/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:11:58 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/14 09:21:32 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx(char c, t_long *data, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->grass, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->appel, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->girl, x, y);
	else if (c == 'E' && data->collect > 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->house, x, y);
	else if (c == 'E' && data->collect == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exi, x, y);
}

void	ft_draw(t_long	*data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] && i < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			ft_mlx(data->map[i][j], data, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
