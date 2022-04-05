/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:37:20 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/11 15:14:39 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_death(t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	img->position = img->dead_body;
	print_map(*img->m_par, *img, img->m_par->map);
	mlx_string_put(img->mlx, img->mlx_win, 32, \
			img->m_par->y_max * IM_SZ, 0x00FFFFFF, "you died\n");
	return (2);
}

static void	ft_loop_patrol(t_data *img, int step, int i, int j)
{
	if (step < 4)
	{
		if (img->m_par->map[i][j + 1] == '0')
		{
			img->m_par->map[i][j] = '0';
			img->m_par->map[i][j + 1] = 'B';
		}
		else if (img->m_par->map[i][j + 1] == 'P')
			ft_death(img);
	}
	else if (step < 8)
	{
		if (img->m_par->map[i][j - 1] == '0')
		{
			img->m_par->map[i][j] = '0';
			img->m_par->map[i][j - 1] = 'B';
		}
		else if (img->m_par->map[i][j - 1] == 'P')
			ft_death(img);
	}
}

void	ft_enem_patrol(t_data *img, char **map)
{
	int			i;
	int			j;
	static int	step = 0;

	i = 0;
	j = 0;
	while (i < img->m_par->y_max)
	{
		while (j < img->m_par->x_max)
		{
			if (map[i][j] == 'B')
			{
				ft_loop_patrol(img, step, i, j);
				if (step < 4)
					j++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	step++;
	if (step == 8)
		step = 0;
	ft_map_out(img);
}

int	ft_anim(t_data *img)
{
	static int	i = 0;

	if (i < 50)
	{
		img->e_stage = img->one_enem;
		i++;
	}
	else if (i < 100)
	{
		img->e_stage = img->sec_enem;
		i++;
	}
	else if (i < 150)
	{
		img->e_stage = img->trid_enem;
		i++;
	}
	else if (i < 200)
		i = 0;
	print_map(*img->m_par, *img, img->m_par->map);
	return (0);
}
