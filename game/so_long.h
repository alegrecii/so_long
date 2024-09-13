/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:51:49 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/30 14:53:57 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "mlx_int.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct s_images
{
	void	*p;
	void	*c;
	void	*w;
	void	*t;
	void	*e;
	void	*f;
	void	*e1;
	void	*e2;
	void	*e3;
	void	*e4;
	void	*e5;
	void	*e6;
	void	*e7;
	void	*e8;
	void	*e9;
	void	*e10;
	void	*e11;
	void	*e12;
	void	*e13;
	void	*e14;
	void	*g4;
	void	*g3;
	void	*g2;
	void	*g1;
	void	*l;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	void	*p5;
	void	*p6;
	void	*p7;
	void	*black;
	void	*n;
}	t_images;

typedef struct s_game
{
	char		**map;
	int			map_lines;
	int			moves;
	void		*mlx;
	t_vector	*pp;
	t_vector	**ghosts;
	void		*win;
	int			coins;
	t_images	*images;
	int			g_n;
	int			w_h;
	int			w_w;
	int			moved;
	int			frame;
	int			dead;
	int			maxf;
	int			f;
	int			marco;
}	t_game;

t_vector	**ghost_creator(t_game *game);
void		ghosts_init(t_game *game);
char		**map_generator(char *file, t_game *game);
size_t		ft_strlen(const char *str);
int			input_manager(int keycode, t_game *game);
int			check_init(int argc, char **argv, t_game *game);
int			updater(t_game *game);
void		ghost_render(t_game *game, t_vector *ghost);
void		ghost_manager(t_game *game);
void		image_creator(t_images *images, void *mlx, int ww, int wh);
void		ft_death(t_game *game);
void		ft_close(t_game *game);
int			echar_check(char **map);
void		moves_counter(t_game *game, void *b);
void		frame_updater(t_game *game);
void		player_render(t_game *game);
int			destroywin(t_game *game);
int			map_check(char *file);
int			path_finder(char **map);
int			char_counter(char **map, char c);
void		render(t_game *game);
void		free_check(int fd, char **map);
int			superfree(t_game *game);
#endif
