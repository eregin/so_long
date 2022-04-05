/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:27:02 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/11 13:31:01 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	ft_is_player(char c)
{
	static int	p = 0;

	if (p == 0 && c == 'P')
	{
		p = 1;
		return ('P');
	}
	else if (c == 'P')
		return ('0');
	return (c);
}

static void	ft_loop(char **mapper, int fd, int y_max)
{
	int		i;
	int		j;
	char	symvol;

	i = 0;
	j = 0;
	while (i < y_max)
	{
		read(fd, &symvol, 1);
		if (symvol == '\n')
		{
			mapper[i][j] = '\0';
			i++;
			j = 0;
			continue ;
		}
		mapper[i][j] = ft_is_player(symvol);
		j++;
	}
	close(fd);
}

char	**map_creator(t_args arg, t_long *map)
{
	int		i;
	int		fd;
	char	**mapper;

	i = 0;
	mapper = (char **)malloc(sizeof(char *) * (map->y_max + 1));
	fd = ft_get_fd(arg);
	while (i < map->y_max)
	{
		mapper[i] = (char *)malloc(sizeof(char) * (map->x_max + 1));
		if (mapper[i] == NULL)
		{
			while (i-- > 0)
				free(mapper[i]);
			free(mapper);
			ft_putstr_fd("Map creation error\n", 2);
			return (NULL);
		}
		i++;
	}
	mapper[i] = NULL;
	ft_loop(mapper, fd, map->y_max);
	return (mapper);
}

/*int	main(int argc, char **argv, char **envp)
{
	t_args	arg;
	t_long	par;
	int		val;
	char	**map;
	int i = 0;

	arg.argc = argc;
	arg.argv = argv;
	arg.envp = envp;
	val = map_checker(arg, &par);
	if (val == 1)
	{
		map = map_creator(arg, &par);
		while(map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
	}
	return 1;
}*/
