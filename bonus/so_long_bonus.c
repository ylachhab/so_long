/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:00:23 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/17 22:49:53 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animation(t_long *data)
{
	data->animation = malloc(sizeof(void **) * 10);
	if (!data->animation)
		return ;
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
	static int	i;

	if (i == 9000)
		i = 0;
	position_enemy(data);
	if (i == 0)
		draw_anim(data, 0);
	else if (i == 1000)
		draw_anim(data, 1);
	else if (i == 2000)
		draw_anim(data, 2);
	else if (i == 3000)
		draw_anim(data, 3);
	else if (i == 4000)
		draw_anim(data, 4);
	else if (i == 5000)
		draw_anim(data, 5);
	else if (i == 6000)
		draw_anim(data, 6);
	else if (i == 7000)
		draw_anim(data, 7);
	else if (i == 8000)
		draw_anim(data, 8);
	i++;
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
		mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_putstr("error\n");
}
