/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:51:02 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/05 15:40:36 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mov_up(t_data *img)
{
	int	code;

	code = 1;
	if (img->m_par->map[img->m_par->pl_y - 1][img->m_par->pl_x] != '1')
	{
		if (img->m_par->map[img->m_par->pl_y - 1][img->m_par->pl_x] == 'E')
		{
			if (img->m_par->gem_count == 0)
				code = 0;
			else
				return (code);
		}
		if (img->m_par->map[img->m_par->pl_y - 1][img->m_par->pl_x] == 'C')
			img->m_par->gem_count--;
		img->m_par->map[img->m_par->pl_y][img->m_par->pl_x] = '0';
		img->m_par->map[img->m_par->pl_y - 1][img->m_par->pl_x] = 'P';
		img->m_par->pl_y--;
		img->position = img->u_play;
		ft_shell_out();
	}
	if (code == 0)
		ft_kill_proc(img);
	return (code);
}

int	ft_mov_down(t_data *img)
{
	int	code;

	code = 1;
	if (img->m_par->map[img->m_par->pl_y + 1][img->m_par->pl_x] != '1')
	{
		if (img->m_par->map[img->m_par->pl_y + 1][img->m_par->pl_x] == 'E')
		{
			if (img->m_par->gem_count == 0)
				code = 0;
			else
				return (code);
		}
		if (img->m_par->map[img->m_par->pl_y + 1][img->m_par->pl_x] == 'C')
			img->m_par->gem_count--;
		img->m_par->map[img->m_par->pl_y][img->m_par->pl_x] = '0';
		img->m_par->map[img->m_par->pl_y + 1][img->m_par->pl_x] = 'P';
		img->m_par->pl_y++;
		img->position = img->d_play;
		ft_shell_out();
	}
	if (code == 0)
		ft_kill_proc(img);
	return (code);
}

int	ft_mov_left(t_data *img)
{
	int	code;

	code = 1;
	if (img->m_par->map[img->m_par->pl_y][img->m_par->pl_x - 1] != '1')
	{
		if (img->m_par->map[img->m_par->pl_y][img->m_par->pl_x - 1] == 'E')
		{
			if (img->m_par->gem_count == 0)
				code = 0;
			else
				return (code);
		}
		if (img->m_par->map[img->m_par->pl_y][img->m_par->pl_x - 1] == 'C')
			img->m_par->gem_count--;
		img->m_par->map[img->m_par->pl_y][img->m_par->pl_x] = '0';
		img->m_par->map[img->m_par->pl_y][img->m_par->pl_x - 1] = 'P';
		img->m_par->pl_x--;
		img->position = img->l_play;
		ft_shell_out();
	}
	if (code == 0)
		ft_kill_proc(img);
	return (code);
}

int	ft_mov_right(t_data *img)
{
	int	code;

	code = 1;
	if (img->m_par->map[img->m_par->pl_y][img->m_par->pl_x + 1] != '1')
	{
		if (img->m_par->map[img->m_par->pl_y][img->m_par->pl_x + 1] == 'E')
		{
			if (img->m_par->gem_count == 0)
				code = 0;
			else
				return (code);
		}
		if (img->m_par->map[img->m_par->pl_y][img->m_par->pl_x + 1] == 'C')
			img->m_par->gem_count--;
		img->m_par->map[img->m_par->pl_y][img->m_par->pl_x] = '0';
		img->m_par->map[img->m_par->pl_y][img->m_par->pl_x + 1] = 'P';
		img->m_par->pl_x++;
		img->position = img->r_play;
		ft_shell_out();
	}
	if (code == 0)
		ft_kill_proc(img);
	return (code);
}
