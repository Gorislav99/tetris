/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_tetrimino.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:11:05 by mgorczan          #+#    #+#             */
/*   Updated: 2019/03/16 15:11:09 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	valid_tetrimino(char *buff, int rd, t_coord *coord)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	if (rd < 20)
		return (0);
	while (i < 20)
	{
		if ((i + 1) % 5 == 0 && buff[i] != '\n')
			return (0);
		if ((sum = valid_sharps(buff, coord, i++, sum)) == -1)
			return (0);
	}
	if (sum != 4)
		return (0);
	if (buff[20] != '\n' && buff[20] != '\0')
		return (0);
	if (!valid_coord(coord))
		return (0);
	return (1);
}

int	valid_sharps(char *buff, t_coord *coord, int i, int sum)
{
	if ((i + 1) % 5 != 0)
	{
		if (buff[i] == '#')
		{
			if (++sum > 4)
				return (-1);
			coord[sum - 1].y = i / 5;
			coord[sum - 1].x = i % 5;
		}
		if (buff[i] != '#' && buff[i] != '.')
			return (-1);
	}
	return (sum);
}

int	valid_coord(t_coord *coord)
{
	int i;
	int k;
	int sum;

	i = 0;
	sum = 0;
	while (i < 4)
	{
		if (!(k = add_coord(i, coord)))
			return (0);
		else
			sum += k;
		i++;
	}
	if (sum < 6)
		return (0);
	return (1);
}

int	add_coord(int i, t_coord *coord)
{
	int j;
	int k;
	int x;
	int y;

	j = 0;
	k = 0;
	while (j < 4)
	{
		y = coord[i].y - coord[j].y;
		x = coord[i].x - coord[j].x;
		if (ABS(y) == 0)
			if (ABS(x) == 1)
				k++;
		if (ABS(y) == 1)
			if (ABS(x) == 0)
				k++;
		j++;
	}
	if (!k)
		return (0);
	return (k);
}
