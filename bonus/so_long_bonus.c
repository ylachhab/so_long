/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:00:23 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/16 02:27:38 by ylachhab         ###   ########.fr       */
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
			if (data->map[i][j] == 'V')
			{
				data->xv = j;
				data->yv = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	game_load(t_long *data)
{
	data->mlx_ptr = mlx_init();
	data->animation = malloc(sizeof(void **) * 10);
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
	data->animation[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/manster1.xpm", &data->img_width, &data->img_height);
	data->animation[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/manster2.xpm", &data->img_width, &data->img_height);
	data->animation[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/manster3.xpm", &data->img_width, &data->img_height);
	data->animation[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/manster4.xpm", &data->img_width, &data->img_height);
	data->animation[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/manster5.xpm", &data->img_width, &data->img_height);
	data->animation[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/manster6.xpm", &data->img_width, &data->img_height);
	data->animation[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/manster7.xpm", &data->img_width, &data->img_height);
	data->animation[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/manster8.xpm", &data->img_width, &data->img_height);
	data->animation[8] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/manster9.xpm", &data->img_width, &data->img_height);
	data->animation[9] = NULL;
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

int	render_next_frame(t_long *data)
{
	static int i;

	if (i == 9000)
		i = 0;
		if (i == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->animation[0],
			data->xv * 64, data->yv * 64);
		else if (i == 1000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->animation[1],
			data->xv * 64, data->yv * 64);
		else if (i == 2000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->animation[2],
			data->xv * 64, data->yv * 64);
		else if (i == 3000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->animation[3],
			data->xv * 64, data->yv * 64);
		else if (i == 4000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->animation[4],
			data->xv * 64, data->yv * 64);
		else if (i == 5000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->animation[5],
			data->xv * 64, data->yv * 64);
		else if (i == 6000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->animation[6],
			data->xv * 64, data->yv * 64);
		else if (i == 7000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->animation[7],
			data->xv * 64, data->yv * 64);
		else if (i == 8000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->animation[8],
			data->xv * 64, data->yv * 64);

		i++;
	return (1);
}

int	main(int ac, char *av[])
{
	t_long		data;

	if (ac == 2)
	{
		ft_parsing(&data, av[1]);
		position_enemy(&data);
		game_load(&data);
		// ft_printf("*******hello*******\n");
		ft_draw(&data);
		mlx_hook(data.win_ptr, 2, 0, &move, &data);
		mlx_hook(data.win_ptr, 17, 0, &cross_click, &data);
		mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_putstr("error\n");
}
