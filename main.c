#include "ft_printf.h"
#define VALUE "%+d", LONG_MAX

int		main(int ac, char **av)
{
	int		nb;
	int		ret;
	char	c;

	nb = 0;
	c = 'a';
	if (ac < 2)
		return (0);
	setlocale(LC_ALL, "");
	ft_printf(VALUE);
	printf("\nvs\n");
	ret = printf(VALUE);
	return (0);
}
