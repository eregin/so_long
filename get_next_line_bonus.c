/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:59:53 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/07 13:20:14 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*ft_nstrdup(const char *s1)
{
	int		i;
	int		size;
	char	*buf;

	size = ft_strlen(s1);
	buf = (char *)malloc(sizeof(char) * (size + 2));
	if (buf == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		buf[i] = s1[i];
		i++;
	}
	buf[i] = '\n';
	buf[i + 1] = '\0';
	return (buf);
}

static char	*gflag(char *ost, int *flag, int fd)
{
	char	*check_point;
	char	*prefinal;

	if (fd < 0)
	{
		*flag = 0;
		return (NULL);
	}
	check_point = ft_strchr(ost, '\n');
	if (check_point)
	{
		check_point[0] = '\0';
		prefinal = ft_nstrdup(ost);
		ft_strlcpy(ost, (check_point + 1), BUFFER_SIZE + 1);
		*flag = 0;
	}
	else
	{
		prefinal = ft_strdup(ost);
		ost[0] = '\0';
	}
	return (prefinal);
}

static void	checkend(char **final)
{
	if (*final != NULL && *final[0] == '\0')
	{
		free(*final);
		*final = NULL;
	}
}

static int	ifwr(int wr)
{
	if (wr == -1)
		wr = 0;
	return (wr);
}

char	*get_next_line(int fd)
{
	static char	ost[10243][BUFFER_SIZE + 1];
	char		buf[BUFFER_SIZE + 1];
	int			wrcount;
	char		*rpoint;
	char		*fpoint;

	wrcount = 1;
	fpoint = gflag(ost[fd], &wrcount, fd);
	while (wrcount > 0)
	{
		wrcount = read(fd, buf, BUFFER_SIZE);
		buf[ifwr(wrcount)] = '\0';
		rpoint = ft_strchr(buf, '\n');
		if (rpoint)
		{
			ft_strlcpy(ost[fd], (rpoint + 1), BUFFER_SIZE + 1);
			rpoint[1] = '\0';
			wrcount = 0;
		}
		rpoint = fpoint;
		fpoint = ft_strjoin(fpoint, buf);
		free(rpoint);
	}
	checkend(&fpoint);
	return (fpoint);
}
