/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:25:56 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/11 12:09:51 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_long par, t_data img, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < par.y_max)
	{
		while (j < par.x_max)
		{
			if (map[i][j] == '1' || map[i][j] == '0')
				ft_env_render(img, i, j, map[i][j]);
			else if (map[i][j] == 'P')
				ft_player_render(img, i, j);
			else if (map[i][j] == 'E')
				ft_exit_render(img, i, j);
			else if (map[i][j] == 'C')
				ft_collect_render(img, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}

int	ft_key_action(int keycode, t_data *img)
{
	int	code;

	code = 0;
	if (keycode == UP)
		code = ft_mov_up(img);
	else if (keycode == DOWN)
		code = ft_mov_down(img);
	else if (keycode == LEFT)
		code = ft_mov_left(img);
	else if (keycode == RIGHT)
		code = ft_mov_right(img);
	else if (keycode == RESET || keycode == ESC)
		ft_kill_proc(img);
	if (code)
	{
		mlx_clear_window(img->mlx, img->mlx_win);
		print_map(*img->m_par, *img, img->m_par->map);
	}
	return (1);
}

void	ft_mlx_init(int wh, t_data *img, t_long par)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, \
			(par.x_max - 1) * IM_SZ, par.y_max * IM_SZ, "so_long");
	img->floor = mlx_xpm_file_to_image(img->mlx, FLOOR, &wh, &wh);
	img->colect = mlx_xpm_file_to_image(img->mlx, COLLECT, &wh, &wh);
	img->wall = mlx_xpm_file_to_image(img->mlx, WALL, &wh, &wh);
	img->exit = mlx_xpm_file_to_image(img->mlx, EXIT, &wh, &wh);
	img->l_play = mlx_xpm_file_to_image(img->mlx, PLAYER_L, &wh, &wh);
	img->r_play = mlx_xpm_file_to_image(img->mlx, PLAYER_R, &wh, &wh);
	img->u_play = mlx_xpm_file_to_image(img->mlx, PLAYER_U, &wh, &wh);
	img->d_play = mlx_xpm_file_to_image(img->mlx, PLAYER_D, &wh, &wh);
	img->position = img->l_play;
}

int	main(int argc, char **argv)
{
	t_args	arg;
	t_long	par;
	t_data	img;

	arg.argc = argc;
	arg.argv = argv;
	if (argc != 2)
	{
		ft_putstr_fd("Error\nNeed map filename", 2);
		return (1);
	}
	if (map_checker(arg, &par))
		par.map = map_creator(arg, &par);
	else
		return (1);
	if (par.map == NULL)
		return (2);
	ft_mlx_init(IM_SZ, &img, par);
	img.m_par = &par;
	print_map(par, img, par.map);
	mlx_hook(img.mlx_win, 2, 0, ft_key_action, &img);
	mlx_hook(img.mlx_win, 17, 0, ft_kill_proc, &img);
	mlx_loop(img.mlx);
}
