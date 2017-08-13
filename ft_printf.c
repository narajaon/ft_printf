#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_env	e;

	init_params(&e);
	e.output_size = 0;
	e.flags.opt.star = 0;
	ft_bzero(e.out_tmp, sizeof(e.out_tmp));
	va_start(e.arg, str);
	fill_funtab(&e);
	print_str((char **)&str, &e);
	va_end(e.arg);
#ifdef DEBUG
	printf("\nwidth |%d|\n", e.flags.width);
	printf("\nprecis |%d|\n", e.flags.precis);
	printf("conv |%c|\n", e.flags.conv);
	printf("min |%c| hash |%c| sign |%c|\
	decal |%c| star |%d|\n",
		e.flags.opt.min, e.flags.opt.hash,
		e.flags.opt.sign, e.flags.opt.decal, e.flags.opt.star);
	NBR(e.cast_id);
#endif
//	printf("\noutput_size |%d|\n", e.output_size);
	return (e.output_size);
}
