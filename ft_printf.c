#include "ft_printf.h"

int		ft_printf(const char *str,...)
{
	t_env	e;

	ft_bzero(&e, sizeof(e));
	va_start(e.arg, str);
	fill_funtab(&e);
	print_str((char **)&str, &e);
	va_end(e.arg);
#ifndef DEBUG
	printf("\nwidth |%d|\n", e.flags.width);
	printf("conv |%c|\n", e.flags.conv);
	printf("min |%c| hash |%c| sign |%c|\
	decal |%c|\n",
		e.flags.opt.min, e.flags.opt.hash,
		e.flags.opt.sign, e.flags.opt.decal);
	NBR(e.cast_id);
	printf("\noutput_size |%d|\n", e.output_size);
#endif
	return (e.output_size);
}
