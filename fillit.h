/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:22:37 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/03 16:22:40 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define ABS(x) (x < 0 ? -1 * x : x)
# include <stdlib.h>
# include "sys/types.h"
# include "sys/stat.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tetrim
{
	t_coord			*coord;
	t_coord			*current_coord;
	char			sign;
	int				width;
	int				height;
	struct s_tetrim	*next;
}					t_tetrim;

typedef struct		s_map
{
	char			**map;
	int				k;
}					t_map;

t_tetrim			*g_tet;
t_map				*g_map;

void				free_global(int flag);
char				**create_map(int k);
void				free_map(char **map, int k);
int					entry(char *argv);
int					read_file(int fd);
int					add_tet(t_coord *coord, char c);
t_tetrim			*add_param(t_coord *coord, char c);
int					valid_tetrimino(char *buff, int rd, t_coord *coord);
int					valid_sharps(char *buff, t_coord *coord, int i, int sum);
int					valid_coord(t_coord *coord);
int					add_coord(int i, t_coord *coord);
void				transposition(t_tetrim *tet);
void				zero_x(t_tetrim *tet);
void				zero_y(t_tetrim *tet);
int					search_square(t_tetrim *tet);
int					bust(void);
int					test(t_tetrim *tet);
int					right(char **map, t_tetrim *tet, int i, int j);
void				ft_putstr(char *p);
void				print_map(char **map, int k);
int					sqrt_tet(int number);
void				clean_tet(t_tetrim *tet);

#endif
