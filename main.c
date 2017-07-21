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

int		get_value_size(long long int value)
{
	if (value < 10)
		return (1);
	return (get_value_size(value / 10) + 1);
}

int		main(int ac, char **av)
{
	int		nb;

	nb = 0;
	if (ac < 2)
		return (0);
	ft_printf(av[1], av[2]);
	return (0);
}
