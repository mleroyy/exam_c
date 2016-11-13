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

void	stock(char *str, char *tab, int *j)
{
	int		i;
	int		k;
	int		insert;

	i = 0;
	k = 0;
	insert = 1;
	while (str[i] != 0)
	{
		while (tab[k] != 0)
		{
			if (tab[k] == str[i])
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
			tab[*j] = str[i];
			(*j)++;
		}
		i++;
	}
	tab[*j] = '\0';
}

int		main(int ac, char **av)
{
	int		j;
	char	tab[256];

	j = 0;
	if (ac != 3)
		ft_putchar('\n');
	else
	{
		stock(av[1], tab, &j);
		stock(av[2], tab, &j);
		ft_putstr(tab);
	}
	return (0);
}
