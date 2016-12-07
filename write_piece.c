/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparment <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:55:36 by vparment          #+#    #+#             */
/*   Updated: 2016/12/07 12:55:40 by vparment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	write_piece(t_piece piece, char **tab_f, t_point cursor)
{
	int	n;

	n = 0;
	while (n < 3)
	{
		tab_f[cursor.y][cursor.x] = piece.c;
		cursor.x = piece.cd[n + 1].x + (cursor.x - piece.cd[n].x);
		cursor.y = piece.cd[n + 1].y + (cursor.y - piece.cd[n].y);
		n++;
	}
	tab_f[cursor.y][cursor.x] = piece.c;
}
