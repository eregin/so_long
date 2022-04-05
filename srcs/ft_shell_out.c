/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:55:31 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/11 14:50:10 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_shell_out(void)
{
	static int	i = 1;
	char		*str;

	str = ft_itoa(i);
	write(1, "STEP : ", 7);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	free(str);
	i++;
}
