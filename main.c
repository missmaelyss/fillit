/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:21:56 by marnaud           #+#    #+#             */
/*   Updated: 2016/12/07 16:25:46 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		usage(int n)
{
	if (n == 1)
		printf("usage: fillit source\n");
	else
		printf("error\n");
	return (0);
}

static void		init(t_tab *tableau, t_point *cursor)
{
	(*tableau).n = 0;
	(*tableau).size = 2;
	(*tableau).tab_f = create_tab((*tableau).size);
	initialise_cursor(cursor);
}

int				main(int ac, char **av)
{
	char		buffer[1024];
	t_piece		*tab;
	t_point		cursor;
	t_point		*tab_cursor;
	t_tab		tableau;

	if (ac != 2)
		return (usage(1));
	init(&tableau, &cursor);
	tableau.fd = open(av[1], O_RDONLY);
	read(tableau.fd, buffer, 1024);
	tableau.nb_p = valid_file(buffer);
	tab_cursor = (t_point *)malloc(sizeof(t_point) * tableau.nb_p);
	if (tableau.nb_p == 0)
		return (usage(2));
	tab = save_piece(buffer, tableau.nb_p);
	tableau.tab_f = write_tab(tab, tableau, cursor, tab_cursor);
	tableau.nb_p = 0;
	while (tableau.tab_f[tableau.nb_p])
	{
		printf("%s\n", tableau.tab_f[tableau.nb_p]);
		tableau.nb_p++;
	}
	return (0);
}
