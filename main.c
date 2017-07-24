#include "ft_printf.h"

int		ft_printf(char *str,...)
{
	t_env	e;

	ft_bzero(&e, sizeof(e));
	va_start(e.arg, str);
	fill_funtab(&e);
	print_str(&str, &e);
	va_end(e.arg);
#ifndef DEBUG
	printf("\nwidth |%d|\n", e.flags.width);
	printf("conv |%c|\n", e.flags.conv);
	printf("min |%c| hash |%c| sign |%c|\
	decal |%c|\n",
		e.flags.opt.min, e.flags.opt.hash,
		e.flags.opt.sign, e.flags.opt.decal);
	printf("output_size |%d|\n", e.output_size);
#endif
	return (e.output_size);
}

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
	ft_printf(av[1], av[2], av[3]);
//	ft_printf(av[1], ft_atoi(av[2]));
	printf("\nvs\n\n");
//	ret = printf(av[1], ft_atoi(av[2]));
	ret = printf(av[1], av[2], av[3]);
	printf("\nreal out %d\n", ret);
	return (0);
}
