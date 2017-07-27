#include "ft_printf.h"
#define VALUE "%hhi", CHAR_MIN - 42

int		main(int ac, char **av)
{
	int		nb;
	int		ret;
	char	c;

	nb = 0;
	c = 'a';
	if (ac < 2)
		return (0);
//	ft_printf(av[1], c);
//	ft_printf(av[1], (long long int)ft_atoi(av[2]));
	ft_printf(VALUE);
//	ft_printf(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
//	printf("a%xb%xc%xd", 0, 55555, 100000);
	printf("\nvs\n");
//	ret = printf(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
	ret = printf(VALUE);
	printf("\nreal out %d\n", ret);
	return (0);
}
