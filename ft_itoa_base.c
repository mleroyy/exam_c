#include <stdlib.h>
#include <stdio.h>

int		ft_count_size(long long int value, long long int base)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (value == 0)
		count = 1;
	else
	{
		while (value > 0)
		{
			count++;
			value = value / base;
		}
	}
	return (count);
}

char	*ft_itoa_base(int value, int base)
{
	unsigned int	val;
	int		count;
	char	*dest;
	int		neg;
	char	digit[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	val = (value < 0) ? -value : value;
	neg = ((value < 0) && (base == 10)) ? 1 : 0;
	//printf("val = %u\n", val);
	//printf("bas = %i\n", base);
	//printf("neg = %i\n", neg);
	count = ft_count_size(val, base) + neg;
	//printf("longueur de la chaine a afficher : %i\n", count);
	if ((dest = (char *)malloc(sizeof(char) * (count + neg + 1))) == NULL)
			return (NULL);
	dest[count] = '\0';
	//printf("valeur de dest[%i] = %c\n", count, dest[count]);
	count--;
	while (count >= 0)
	{
		dest[count] = digit[(val % base)];
		//printf("valeur de dest[%i] = %c\n", count, dest[count]);
		val = val / base;
		count--;
	}
	if (neg == 1)
			dest[0] = '-';
	return (dest);
}

int		main(void)
{
	printf("%s\n", ft_itoa_base(-36400, 10));
	printf("%s\n", ft_itoa_base(36400, 10));
	printf("%s\n", ft_itoa_base(36400, 16));
	printf("%s\n", ft_itoa_base(36400, 2));
	return (0);
}
