#include "fillit.h"

int		main(int ac, char **av)
{
	char		buffer[1024];
	t_piece		*tab;
	t_point		cursor;
	t_point		*tab_cursor;
	t_tab		tableau;

	tableau.n = 0;
	tableau.size = 2;
	tableau.tab_f = create_tab(tableau.size);
	initialise_cursor(&cursor);
	tableau.fd = open(av[1], O_RDONLY);
	read(tableau.fd, buffer, 1024);
	tableau.nb_p = valid_file(buffer);
	tab_cursor = (t_point *)malloc(sizeof(t_point) * tableau.nb_p);
	if (tableau.nb_p == 0)
		return (0);
	tab = save_piece(buffer, tableau.nb_p);
	tableau.tab_f = write_tab(tab, tableau, cursor, tab_cursor);
	tableau.nb_p = 0;
	while(tableau.tab_f[tableau.nb_p])
	{
		printf("%s\n", tableau.tab_f[tableau.nb_p]);
		tableau.nb_p++;
	}
	return (0);
}
