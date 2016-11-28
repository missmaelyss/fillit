#include "fillit.h"
#include <stdio.h>

/*typedef	struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef	struct	s_piece
{
	t_point	cd[4];
	char	c;
}				t_piece;
*/
int		ft_valid_file(char *str);
t_piece	*ft_save_piece(char *str, int nb_p);

int		main(void)
{
	char	*str;
	char	*str2;
	int		nb_p;
	t_piece	*tab;
	int 	n;
	int		n2;

	str2 = "##..\n..##\n....\n....\n";
	str = "....\n..##\n..#.\n..#.\n\n....\n....\n..##\n..##\n\n####\n....\n....\n....\n\n....\n....\n##..\n##..\n\n.##.\n..##\n....\n....\n\n....\n.##.\n..##\n....\n\n.#..\n###.\n....\n....\n\n....\n##..\n#...\n#...\n\n....\n.##.\n..#.\n..#.\n";

	printf("%s\n", str2);
	nb_p = ft_valid_file(str2);
	printf("%d\n", nb_p);
	if (nb_p == 0)
		return (0);
	tab = ft_save_piece(str2, nb_p);
	n2 = 0;
	while (n2 < nb_p)
	{
		n = 0;
		while (n < 4)
		{
			printf("x = %d, y = %d,		char = %c\n", tab[n2].cd[n].x, tab[n2].cd[n].y, tab[n2].c);
			n++;
		}
		printf("\n");
		n2++;
	}
	return (0);
}
