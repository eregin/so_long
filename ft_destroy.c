/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:41:42 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/08 14:12:47 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_map(t_data *img)
{
	int	i;

	i = 0;
	while (img->m_par->map[i] != NULL)
	{
		free(img->m_par->map[i]);
		i++;
	}
	free(img->m_par->map);
}

int	ft_kill_proc(t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	free(img->mlx);
	ft_free_map(img);
	exit(EXIT_SUCCESS);
}
