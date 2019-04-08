/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:59:42 by mgorczan          #+#    #+#             */
/*   Updated: 2019/03/16 14:59:45 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	transposition(t_tetrim *tet)
{
	while (tet != NULL)
	{
		zero_x(tet);
		zero_y(tet);
		tet = tet->next;
	}
}

void	zero_x(t_tetrim *tet)
{
	int j;
	int flag;

	flag = 1;
	j = 0;
	while (flag)
	{
		while (j < 4)
			if (tet->coord[j++].x == 0)
				flag = 0;
		if (flag)
			while (j > 0)
				tet->coord[--j].x -= 1;
	}
	j = 0;
	while (j < 4)
	{
		if (tet->coord[j].x > tet->width)
			tet->width = tet->coord[j].x;
		++j;
	}
	tet->width -= tet->coord[0].x;
}

void	zero_y(t_tetrim *tet)
{
	int j;
	int flag;

	flag = 1;
	j = 0;
	while (flag)
	{
		while (j < 4)
			if (tet->coord[j++].y == 0)
				flag = 0;
		if (flag)
			while (j > 0)
				tet->coord[--j].y -= 1;
	}
	tet->height = tet->coord[3].y;
}
