/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:59:29 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/17 05:00:15 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
