/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:31:03 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/05 18:31:07 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_env_render(t_data img, int i, int j, char c)
{
	if (c == '1')
		mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.wall, j * IM_SZ, i * IM_SZ);
	else if (c == '0')
		mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.floor, j * IM_SZ, i * IM_SZ);
}

void	ft_player_render(t_data img, int i, int j)
{
	mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.floor, j * IM_SZ, i * IM_SZ);
	mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.position, j * IM_SZ, i * IM_SZ);
}

void	ft_exit_render(t_data img, int i, int j)
{
	mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.floor, j * IM_SZ, i * IM_SZ);
	mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.exit, j * IM_SZ, i * IM_SZ);
}

void	ft_collect_render(t_data img, int i, int j)
{
	mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.floor, j * IM_SZ, i * IM_SZ);
	mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.colect, j * IM_SZ, i * IM_SZ);
}

void	ft_enemy_render(t_data img, int i, int j)
{
	mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.floor, j * IM_SZ, i * IM_SZ);
	mlx_put_image_to_window(img.mlx, img.mlx_win, \
			img.e_stage, j * IM_SZ, i * IM_SZ);
}
