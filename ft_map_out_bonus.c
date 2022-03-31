/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_out_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:23:47 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/11 14:53:47 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_checker_init(t_long *map, char *str, int *valid)
{
	if (str == NULL)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		return (0);
	}
	map->x_max = ft_strlen(str);
	map->gem_count = 0;
	valid[0] = 0;
	valid[1] = 0;
	return (1);
}

void	ft_map_out(t_data *img)
{
	static int	i = 0;
	char		*buf;
	char		*str;

	mlx_clear_window(img->mlx, img->mlx_win);
	str = ft_itoa(i);
	buf = ft_strjoin("STEP : ", str);
	free(str);
	str = ft_strjoin(buf, "\n");
	free(buf);
	mlx_string_put(img->mlx, img->mlx_win, 32, \
		img->m_par->y_max * IM_SZ, 0x00FFFFFF, str);
	free(str);
	i++;
}
