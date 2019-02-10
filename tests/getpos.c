#include <stdio.h>

int		*get_pos(char *buf)
{
	int			*pos;
	int			i;
	int 		j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			pos[k++] = j;
		i++;
		j < 4 ? (j++) : (j = 0);
	}
	return(pos);
}

int main()
{
	char buf[21] = {'.', '.', '.', '.', '\n', '.', '#', '.', '.', '\n', '#', '#', '#', '.', '\n', '.', '.', '.', '.', '\n', '\n'};
	int *pos = get_pos(buf);
	int x = 0;
	while (x < 4)
	{
		printf("%i", pos[x]);
		x++;
	}
}
