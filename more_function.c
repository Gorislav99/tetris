/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:05:10 by mgorczan          #+#    #+#             */
/*   Updated: 2019/03/16 15:05:13 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char *p)
{
	while (*p)
		write(1, p++, 1);
}

void	print_map(char **map, int k)
{
	int i;

	i = 0;
	while (i < k)
	{
		ft_putstr(map[i++]);
		ft_putstr("\n");
	}
}

int		sqrt_tet(int number)
{
	int i;

	i = 0;
	while (i * i < number * 4)
		i++;
	return (i);
}

void	clean_tet(t_tetrim *tet)
{
	int q;

	q = 0;
	while (q < 4)
	{
		g_map->map[tet->current_coord[q].y][tet->current_coord[q].x] = '.';
		tet->current_coord[q].y = -1;
		tet->current_coord[q].x = -1;
		q++;
	}
}
