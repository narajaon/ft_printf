#include "ft_printf.h"

void	init_arg(char *str, t_env *e,...)
{
	va_start(e->arg, e);
	print_str(&str, e);
	va_end(e->arg);
}

int		main(int ac, char **av)
{
	t_env		e;
	char		*ptr;

	if (ac != 2)
		return (0);
	ptr = av[1];
	ft_bzero(&e, sizeof(e));
	init_arg(av[1], &e);
#ifdef DEBUG
	printf("\nwidth |%d|\n", e.flags.width);
	printf("conv |%c|\n", e.flags.conv);
	printf("min |%c| hash |%c| sign |%c| decal |%c|\n",
		e.flags.opt.min, e.flags.opt.hash,
		e.flags.opt.sign, e.flags.opt.decal);
//	printf("out |%s|\n", e.output);
#endif
	return (0);
}
