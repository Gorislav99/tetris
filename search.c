/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:46:08 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/02 17:46:11 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	search_square(t_tetrim *tet)
{
	if ((g_map = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (0);
	g_map->k = 0;
	while (tet != NULL)
	{
		++(g_map->k);
		tet = tet->next;
	}
	g_map->k = sqrt_tet(g_map->k);
	if (bust() == 0)
		return (0);
	return (1);
}

int	bust(void)
{
	int i;

	if ((g_map->map = create_map(g_map->k)) == NULL)
		return (0);
	while (1)
	{
		i = 0;
		if (test(g_tet) == 1)
			return (1);
		while (i < g_map->k)
			free(g_map->map[i++]);
		free(g_map->map);
		if ((g_map->map = create_map(++(g_map->k))) == NULL)
			return (0);
	}
	return (1);
}

int	test(t_tetrim *tet)
{
	int i;
	int j;

	i = 0;
	if (tet == NULL)
		return (1);
	while (i < g_map->k)
	{
		j = -1;
		if ((i + tet->height) > (g_map->k - 1))
			return (0);
		while ((++j) < g_map->k)
		{
			if ((j + tet->width) < g_map->k)
				if (g_map->map[i][j + tet->coord[0].x] == '.'
						&& right(g_map->map, tet, i, j))
				{
					if (test(tet->next) == 1)
						return (1);
					clean_tet(tet);
				}
		}
		++i;
	}
	return (0);
}

int	right(char **map, t_tetrim *tet, int i, int j)
{
	int q;

	q = -1;
	while (++q < 4)
		if (map[i + tet->coord[q].y][j + tet->coord[q].x] != '.')
			return (0);
	q = -1;
	while (++q < 4)
	{
		map[i + tet->coord[q].y][j + tet->coord[q].x] = tet->sign;
		tet->current_coord[q].y = i + tet->coord[q].y;
		tet->current_coord[q].x = j + tet->coord[q].x;
	}
	return (1);
}
