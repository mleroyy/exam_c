#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	int		q;
	int		insert;
	char	tab[256];

	i = 0;
	j = 0;
	k = 0;
	q = 0;
	insert = 1;

	if (ac != 3)
		ft_putchar('\n');
	else
	{
		while (av[1][i] != 0)
		{
			while (av[2][j] != 0)
			{
				if (av[1][i] == av[2][j])
				{
					while (tab[k] != 0)
					{
						if (tab [k] == av[1][i])
						{
							insert = 0;
							break;
						}
						else
							insert = 1;
						k++;
					}
					k = 0;
					if (insert == 1)
					{
						tab[q] = av[1][i];
						q++;
					}
				}
				j++;
			}
			j = 0;
			i++;
		}
		ft_putstr(tab);
	}
	return (0);
}
