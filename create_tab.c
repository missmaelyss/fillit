#include "fillit.h"

char	**create_tab(int n)
{
	char	**tab_f;
	int		y;
	int		x;

	y = 0;
	if (!(tab_f = (char **)malloc(sizeof(char *) * (n + 1))))
		return (0);
	while (y < n)
	{
		if (!(tab_f[y] = (char *)malloc(sizeof(char) * (n + 1))))
			return (0);
		x = 0;
		while (x < n)
		{
			tab_f[y][x] = '.';
			x++;
		}
		tab_f[y][n] = '\0';
		y++;
	}
	tab_f[n] = 0;
	return (tab_f);
}
