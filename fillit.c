#include "fillit.h"

char	**create_tab(int n)
{
	char	**tab_f;
	int		y;
	int		x;

	y = 0;
	if(!(tab_f = (char **)malloc(sizeof(char *) * (n + 1))))
		return(0);
	while(y < n)
	{
		if(!(tab_f[y] = (char *)malloc(sizeof(char) * (n + 1))))
			return(0);
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
	return(tab_f);
}

int		check_piece(t_piece piece, char **tab_f, t_point cursor, int size)
{		
	int	n;

	n = 0;
	while(n < 4)
	{
		printf("x = %d, y = %d\n", cursor.x, cursor.y);
		if (cursor.x == size || cursor.y == size)
			return (0);
		if( tab_f[cursor.y][cursor.x] != '.')
			return(0);
		if (n < 3)
		{
			cursor.x = piece.cd[n+1].x + (cursor.x - piece.cd[n].x);
			cursor.y = piece.cd[n+1].y + (cursor.y - piece.cd[n].y);
		}
		n++;
	}

	if( tab_f[cursor.y][cursor.x] != '.')
		return(0);
	return(1);
}

void	write_piece(t_piece piece, char **tab_f, t_point cursor)
{		
	int	n;

	n = 0;
	while(n < 3)
	{
		tab_f[cursor.y][cursor.x] = piece.c;
		cursor.x = piece.cd[n+1].x + (cursor.x - piece.cd[n].x);
		cursor.y = piece.cd[n+1].y + (cursor.y - piece.cd[n].y);
		n++;
	}
	tab_f[cursor.y][cursor.x] = piece.c;
}

void	erase_piece(t_piece piece, char **tab_f, t_point cursor)
{
	int n;

	n = 0;
	while(n < 3)
	{	   
		tab_f[cursor.y][cursor.x] = '.';
		cursor.x = piece.cd[n+1].x + (cursor.x - piece.cd[n].x);
		cursor.y = piece.cd[n+1].y + (cursor.y - piece.cd[n].y);
		n++;
	}
	tab_f[cursor.y][cursor.x] = '.';
}

char	**write_tab(t_piece *tab, int nb_p)
  {
  char	**tab_f;
  int 	size;
  t_point	cursor;
  int		n;
  t_point	*tab_cursor;
  int		nb;
  int		i;

  tab_cursor = (t_point *)malloc(sizeof(t_point) * nb_p);
  cursor.x = 0;
  cursor.y = 0;
  size = 2;
  n = 0;
  tab_f = create_tab(size);
  while (n < nb_p)
  {
  if (check_piece(tab[n], tab_f, cursor, size)) 
  {
  write_piece(tab[n], tab_f, cursor);
  tab_cursor[n] = cursor;
  cursor.x = 0;
  cursor.y = 0;
  n++;
  i = 1;
  }
  else if (!(cursor.x == size - 1 && cursor.y == size - 1))
  {
  i = 2;
  if (cursor.x < size - 1)
  cursor.x++;
  else
  {
  cursor.y++;
  cursor.x = 0;
  }
  }
  else {
  if (n == 0)
  {
  i = 4;
  n = 0;
  cursor.x = 0;
  cursor.y = 0;
  size++;
  free(tab_f);
  tab_f = create_tab(size);
  }
  else
  {
  i = 3;
  n--;
  cursor = tab_cursor[n];
  erase_piece(tab[n], tab_f, cursor);
  if (cursor.x < size - 1)
  cursor.x++;
  else
  {
  cursor.y++;
  cursor.x = 0;
  }
  }
  }
  nb = 0;
  while (tab_f[nb])
  {
  printf("%s\n", tab_f[nb]);
  nb++;
  }
  printf("%d\nn = %d, x = %d, y = %d, size = %d", i, n, cursor.x, cursor.y, size);
printf("\n\n");
}
return (tab_f);
}
