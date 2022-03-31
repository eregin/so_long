/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:38:03 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/11 16:32:28 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_wall(char *str, int max)
{
	int	i;

	i = 0;
	while (i < (max - 1))
	{
		if (str[i] != '1')
		{
			ft_putstr_fd("Error\nInvalid map\n", 2);
			free(str);
			return (0);
		}
		i++;
	}
	if (str[i] != '\n')
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		free(str);
		exit(EXIT_FAILURE);
	}
	return (1);
}

static int	check_letter(char *str, t_long *map, int y, int *valid)
{
	int	x;

	x = -1;
	while (++x < map->x_max)
	{
		if (str[x] != '1' && str[x] != 'B' && str[x] != '0' \
			&& str[x] != 'P' && str[x] != 'C' \
			&& str[x] != 'E' && str[x] != '\n')
		{
			*valid = 0;
			free(str);
			return (0);
		}
		if (str[x] == 'P' && valid[0] == 0)
		{
			map->pl_x = x;
			map->pl_y = y;
			valid[0] = 1;
		}
		if (str[x] == 'E' && valid[1] == 0)
			valid[1] = 1;
		if (str[x] == 'C')
			map->gem_count++;
	}
	return (1);
}

static int	check_space(char *str, t_long *map, int y, int *valid)
{
	if (str[0] != '1' || str[map->x_max - 2] != '1' \
			|| (ft_strlen(str) != map->x_max))
	{
		valid[0] = 0;
		free(str);
		return (0);
	}
	return (check_letter(str, map, y, valid));
}

static int	ft_check_loop(char *str, int fd, t_long *map, int *valid)
{
	int		y;
	char	*buf;

	y = 1;
	buf = NULL;
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL && buf == NULL)
			return (0);
		if (str == NULL)
		{
			if (!check_wall(buf, map->x_max))
				return (0);
			break ;
		}
		if (str != NULL && buf != NULL)
			free(buf);
		if (!check_space(str, map, y++, valid))
			return (0);
		buf = str;
	}
	free(buf);
	close(fd);
	return (y);
}

int	map_checker(t_args arg, t_long *map)
{
	int		fd;
	char	*str[2];
	int		valid[2];

	fd = ft_get_fd(arg);
	str[0] = get_next_line(fd);
	str[1] = str[0];
	if (!ft_checker_init(map, str[0], valid))
		return (0);
	if (!check_wall(str[0], map->x_max))
		return (0);
	map->y_max = ft_check_loop(str[0], fd, map, valid);
	if (map->gem_count == 0)
		valid[0] = 0;
	if (valid[0] == 0 || valid[1] == 0)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		free(str[0]);
		return (0);
	}
	free(str[1]);
	return (1);
}
