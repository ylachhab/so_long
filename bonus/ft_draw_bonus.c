/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:11:58 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/19 03:17:02 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_load(t_long *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x * 64,
			data->y * 64, "so_long");
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/6.xpm",
			&data->img_width, &data->img_height);
	data->grass = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/grass.xpm",
			&data->img_width, &data->img_height);
	data->appel = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/appel.xpm",
			&data->img_width, &data->img_height);
	data->girl = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/girl.xpm",
			&data->img_width, &data->img_height);
	data->house = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/house.xpm",
			&data->img_width, &data->img_height);
	data->exi = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exit.xpm",
			&data->img_width, &data->img_height);
	if (!data->mlx_ptr || !data->win_ptr || !data->wall || !data->grass
		|| !data->appel || !data->girl || !data->house || !data->exi)
		exit_error(data);
	ft_animation(data);
}

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
