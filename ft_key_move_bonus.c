/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:57:40 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/14 16:38:43 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_initialize_var(t_long *data)
{
	data->exit = 0;
	data->player = 0;
	data->collect = 0;
	data->x = 0;
	data->y = 0;
	data->oldx = 0;
	data->xpl = 0;
	data->ypl = 0;
}

int	cross_click(t_long	*data)
{
	ft_destroy(data);
	exit(0);
	return (1);
}

int	my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
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
