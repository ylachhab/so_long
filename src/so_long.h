/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:09:00 by ylachhab          #+#    #+#             */
/*   Updated: 2023/02/16 03:40:29 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_long
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		exit;
	int		player;
	int		collect;
	int		x;
	int		y;
	int		oldx;
	int		xpl;
	int		ypl;
	void	*wall;
	void	*grass;
	void	*girl;
	void	*appel;
	void	*house;
	void	*exi;
	int		img_width;
	int		img_height;
	int		coin;
}				t_long;

void	ft_initialize_var(t_long *data);
void	valid_map(t_long *data);
void	rectangularmap(t_long *data, char *str);
int		my_strlen(char	*s);
int		checkfile(char	*str);
void	mallocmap(t_long *data, char *str);
void	stockmap(t_long *data, char *s);
int		checkmap(char c);
void	afficherror(t_long *data);
void	m_map(t_long *data);
void	containmap(t_long *data);
void	ft_parsing(t_long *data, char *str);
void	flood_fill(t_long *data, int y, int x);
void	ft_print_error(t_long *data);
void	ft_check_error(t_long *data);
void	position_player(t_long *data);
void	changep(t_long *data, char *s);
void	map_newline(t_long *data);
int		ft_open(char *str);
int		cross_click(t_long	*data);
void	exit_error(t_long *data);
void	ft_draw(t_long	*data);
void	ft_right(t_long *data, int keycode);
void	ft_left(t_long *data, int keycode);
void	ft_down(t_long	*data, int keycode);
void	ft_up(t_long	*data, int keycode);
void	ft_right_d(t_long *data, int keycode);
void	ft_left_a(t_long *data, int keycode);
void	ft_down_s(t_long	*data, int keycode);
void	ft_up_w(t_long	*data, int keycode);
void	ft_destroy(t_long	*data);
void	ft_esc(int keycode, t_long	*data);

#endif
