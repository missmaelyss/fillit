

#ifndef	FILLIT_H

# define FILLIT_H

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef	struct	s_piece
{
	t_point	cd[4];
	char	c;
}		t_piece;

#endif

