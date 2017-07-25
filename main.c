#include "ft_printf.h"

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
	ft_printf(av[1], LONG_MAX);
//	ft_printf(av[1], ft_aoi(av[2]));
	printf("\nvs\n\n");
//	ret = printf(av[1], ft_atoi(av[2]));
	ret = printf(av[1], LONG_MAX);
	printf("\nreal out %d\n", ret);
	return (0);
}
