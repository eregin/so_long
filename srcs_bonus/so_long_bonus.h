/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:23:18 by ereginia          #+#    #+#             */
/*   Updated: 2022/04/05 11:56:45 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# include "../libft/libft.h"

# define PLAYER_L "pics/player_left.xpm"
# define PLAYER_R "pics/player_right.xpm"
# define PLAYER_U "pics/player_up.xpm"
# define PLAYER_D "pics/player_down.xpm"
# define WALL "pics/wall.xpm"
# define FLOOR "pics/floor.xpm"
# define COLLECT "pics/collectables.xpm"
# define EXIT "pics/exit.xpm"
# define ENEMY_1 "pics/enemy_1.xpm"
# define ENEMY_2 "pics/enemy_2.xpm"
# define ENEMY_3 "pics/enemy_3.xpm"
# define DEAD_BODY "pics/dead_body.xpm"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define RESET 15
# define ESC 53

# ifndef IM_SZ
#  define IM_SZ 32
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_long
{
	int		gem_count;
	int		pl_x;
	int		pl_y;
	int		x_max;
	int		y_max;
	char	**map;
}	t_long;

typedef struct s_args
{
	int		argc;
	char	**argv;
}	t_args;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*floor;
	void	*colect;
	void	*wall;
	void	*exit;
	void	*l_play;
	void	*r_play;
	void	*u_play;
	void	*d_play;
	void	*one_enem;
	void	*sec_enem;
	void	*trid_enem;
	void	*dead_body;
	void	*e_stage;
	void	*position;
	t_long	*m_par;
}				t_data;

int		ft_get_fd(t_args arg);
char	*get_next_line(int fd);
int		map_checker(t_args arg, t_long *map);
char	**map_creator(t_args arg, t_long *map);
int		ft_key_action(int keycode, t_data *img);
int		ft_mov_up(t_data *img);
int		ft_mov_down(t_data *img);
int		ft_mov_left(t_data *img);
int		ft_mov_right(t_data *img);
int		ft_anim(t_data *img);
int		ft_kill_proc(t_data *img);
int		ft_checker_init(t_long *map, char *str, int *valid);
void	ft_map_out(t_data *img);
void	ft_env_render(t_data img, int i, int j, char c);
void	ft_player_render(t_data img, int i, int j);
void	ft_exit_render(t_data img, int i, int j);
void	ft_collect_render(t_data img, int i, int j);
void	ft_enemy_render(t_data img, int i, int j);
void	print_map(t_long par, t_data img, char **map);
void	ft_enem_patrol(t_data *img, char **map);
int		ft_death(t_data *img);

#endif
