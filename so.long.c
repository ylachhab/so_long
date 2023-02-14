/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:00:23 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/14 09:21:32 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	game_load(t_long *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x * 64,
			data->y * 64, "so_long");
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "6.xpm", &data->img_width,
			&data->img_height);
	data->grass = mlx_xpm_file_to_image(data->mlx_ptr, "grass.xpm",
			&data->img_width, &data->img_height);
	data->appel = mlx_xpm_file_to_image(data->mlx_ptr, "appel.xpm",
			&data->img_width, &data->img_height);
	data->girl = mlx_xpm_file_to_image(data->mlx_ptr, "girl.xpm",
			&data->img_width, &data->img_height);
	data->house = mlx_xpm_file_to_image(data->mlx_ptr, "house.xpm",
			&data->img_width, &data->img_height);
	data->exi = mlx_xpm_file_to_image(data->mlx_ptr, "exit.xpm",
			&data->img_width, &data->img_height);
}

void	ft_esc(int keycode, t_long	*data)
{
	if (keycode == 53)
	{
		ft_destroy(data);
		exit(0);
	}
}

int	move(int keycode, t_long *data)
{
	static int	i;

	if (keycode == 125 || keycode == 124 || keycode == 123 || keycode == 126
		|| keycode == 2 || keycode == 0 || keycode == 1 || keycode == 13
		|| keycode == 53)
		i++;
	ft_printf("%d\n", i);
	ft_esc(keycode, data);
	ft_right(data, keycode);
	ft_left(data, keycode);
	ft_down(data, keycode);
	ft_up(data, keycode);
	ft_right_d(data, keycode);
	ft_left_a(data, keycode);
	ft_down_s(data, keycode);
	ft_up_w(data, keycode);
	return (1);
}

int	main(int ac, char *av[])
{
	t_long		data;

	if (ac == 2)
	{
		ft_parsing(&data, av[1]);
		game_load(&data);
		ft_draw(&data);
		mlx_hook(data.win_ptr, 2, 0, &move, &data);
		mlx_hook(data.win_ptr, 17, 0, &cross_click, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_putstr("error\n");
}