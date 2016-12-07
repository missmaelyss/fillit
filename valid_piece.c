/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparment <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:13:25 by vparment          #+#    #+#             */
/*   Updated: 2016/12/07 11:15:14 by vparment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		test_touch(t_piece test, int n, int n2, int *nb_touch)
{
	if (test.cd[n].x == test.cd[n2].x && test.cd[n].y == test.cd[n2].y + 1)
		(*nb_touch)++;
	if (test.cd[n].x == test.cd[n2].x && test.cd[n].y == test.cd[n2].y - 1)
		(*nb_touch)++;
	if (test.cd[n].y == test.cd[n2].y && test.cd[n].x == test.cd[n2].x + 1)
		(*nb_touch)++;
	if (test.cd[n].y == test.cd[n2].y && test.cd[n].x == test.cd[n2].x - 1)
		(*nb_touch)++;
}

int				valid_piece(t_piece test)
{
	int		nb_touch;
	int		n;
	int		n2;

	n = 0;
	nb_touch = 0;
	while (n < 4)
	{
		n2 = 0;
		while (n2 < 4)
		{
			if (n2 == n)
				n2++;
			test_touch(test, n, n2, &nb_touch);
			n2++;
		}
		n++;
	}
	if (nb_touch < 6)
		return (1);
	return (0);
}
