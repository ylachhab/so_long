/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_utils_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:59:29 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/21 00:08:11 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	null_cheaker(t_long *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!data->animation[i++])
			exit_error(data);
	}
}

void	afficherror(t_long *data)
{
	ft_putstr("error :(\n");
	exit_error(data);
}

void	ft_counter(t_long *data, char c)
{
	if (c == 'P')
		data->player++;
	else if (c == 'E')
		data->exit++;
	else if (c == 'C')
		data->collect++;
	else if (c == 'V')
		data->enemy++;
}

int	ft_open(char *str)
{
	int		fd;
	t_long	data;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit_error(&data);
	return (fd);
}

void	ft_put_string(t_long *data)
{
	data->line = ft_itoa(data->coin);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 15,
		0000000, "THE MOVE:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30,
		0000000, data->line);
	free(data->line);
}
