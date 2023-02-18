/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:57:40 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/17 22:12:01 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static size_t	numberof_n(long int n)
{
	long	nb;

	nb = 1;
	while (n >= 10)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	long		a;
	int			len;
	char		*res;
	int			i;

	a = n;
	if (n < 0)
		a *= -1;
	len = numberof_n(a);
	if (n < 0)
		len ++;
	res = malloc(len + 1);
	if (res == 0)
		return (0);
	res[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		res[i] = (a % 10) + '0';
		a /= 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

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
	data->xv = 0;
	data->yv = 0;
	data->enemy = 0;
	data->coin = 0;
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
