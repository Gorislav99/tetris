/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:17:57 by mgorczan          #+#    #+#             */
/*   Updated: 2019/03/16 14:18:02 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			entry(char *argv)
{
	int	fd;

	if ((fd = open(argv, O_RDWR)) == -1)
		return (0);
	if ((read_file(fd)) == 0)
	{
		close(fd);
		return (0);
	}
	return (1);
}

int			read_file(int fd)
{
	int			rd;
	char		buff[22];
	char		c;
	t_coord		*coord;

	g_tet = NULL;
	c = 'A';
	while ((rd = read(fd, buff, 21)))
	{
		if (!(coord = (t_coord*)malloc(sizeof(t_coord) * 4)))
			return (0);
		buff[rd] = '\0';
		if (valid_tetrimino(buff, rd, coord) == 0)
		{
			free(coord);
			return (0);
		}
		if (add_tet(coord, c++) == 0)
			return (0);
	}
	if (rd == -1 || buff[20] != '\0')
		return (0);
	return (1);
}

int			add_tet(t_coord *coord, char c)
{
	static t_tetrim	*tet;

	if (g_tet == NULL)
	{
		if ((g_tet = add_param(coord, c)) == NULL)
			return (0);
		tet = g_tet;
	}
	else
	{
		if ((tet->next = add_param(coord, c)) == NULL)
			return (0);
		tet = tet->next;
	}
	return (1);
}

t_tetrim	*add_param(t_coord *coord, char c)
{
	t_tetrim	*tet;
	int			j;

	j = 0;
	if ((tet = (t_tetrim*)malloc(sizeof(t_tetrim))) == NULL)
		return (NULL);
	if ((tet->current_coord = (t_coord*)malloc(sizeof(t_coord) * 4)) == NULL)
		return (NULL);
	tet->coord = coord;
	tet->sign = c;
	tet->width = 0;
	tet->height = 0;
	tet->next = NULL;
	while (j < 4)
	{
		tet->current_coord[j].y = -1;
		tet->current_coord[j++].x = -1;
	}
	if (g_tet == NULL)
		g_tet = tet;
	return (tet);
}
