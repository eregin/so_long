/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:36:11 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/08 18:29:07 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_ber(const char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'r' || str[len - 2] != 'e'\
		|| str[len - 3] != 'b' || str[len - 4] != '.')
	{
		ft_putstr_fd("Error\nwrong file extention\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_get_fd(t_args arg)
{
	int	fd;

	ft_check_ber(arg.argv[1]);
	fd = open(arg.argv[1], O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nfile not found\n", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
