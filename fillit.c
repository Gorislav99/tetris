/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:18:52 by mgorczan          #+#    #+#             */
/*   Updated: 2019/03/16 14:18:57 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file target_file\n");
		return (0);
	}
	if ((entry(argv[1])) == 0)
	{
		free_global(0);
		ft_putstr("error\n");
		return (0);
	}
	transposition(g_tet);
	if (search_square(g_tet) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	print_map(g_map->map, g_map->k);
	free_global(1);
	return (0);
}

void	free_global(int flag)
{
	int			i;
	t_tetrim	*tet;

	i = 0;
	while (g_tet != NULL)
	{
		tet = g_tet->next;
		free(g_tet->coord);
		free(g_tet->current_coord);
		free(g_tet);
		g_tet = tet;
	}
	if (flag == 0)
		return ;
	while (i < g_map->k)
		free(g_map->map[i++]);
	free(g_map->map);
	free(g_map);
}

char	**create_map(int k)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	if (!(map = (char**)malloc(sizeof(char*) * k)))
		return (NULL);
	while (++i < k)
		if (!(map[i] = (char*)malloc(sizeof(char) * (k + 1))))
			return (NULL);
	i = 0;
	while (i < k)
	{
		j = 0;
		while (j < k)
			map[i][j++] = '.';
		map[i++][j] = '\0';
	}
	return (map);
}

void	free_map(char **map, int k)
{
	int i;

	i = 0;
	while (i < k)
		free(map[i++]);
	free(map);
}
