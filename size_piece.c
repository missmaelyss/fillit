#include "fillit.h"

int	size_piece(t_piece piece)
{
	int	c;
	int	n;
	int	val[4];
//	val contient xmin, xmax, ymin et ymax

	n = 0;
	val[0] = piece.cd[n].x;
	val[1] = piece.cd[n].x;
	val[2] = piece.cd[n].y;
	val[3] = piece.cd[n].y;
	while (n < 4)
	{
		if (piece.cd[n].x < val[0])
			val[0] = piece.cd[n].x;
		if (piece.cd[n].x > val[1])
			val[1] = piece.cd[n].x;
		if (piece.cd[n].y < val[2])
			val[2] = piece.cd[n].y;
		if (piece.cd[n].y > val[3])
			val[3] = piece.cd[n].y;
		n++;
	}
	if (val[1] - val[0] > val[3] - val[2])
		c = (val[1] - val[0]) + 1;
	else
		c = (val[3] - val[2]) + 1;
	return (c);
}
