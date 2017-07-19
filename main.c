#include "ft_printf.h"

void	opt_resolver(char c, t_opt *opt)
{
	if (c == ' ' || c == '+')
		opt->sign = (c == ' ' && opt->sign != '+') ? ' ' : '+';
	else if (c == '-')
		opt->min = '-';
	else if (c == '#')
		opt->hash = '#';
	else if (c == '0')
		opt->decal = '0';
}

void	get_opt(char **str, t_env *e)
{
	char		option;

	while ((option = is_opt(*str)))
	{
		opt_resolver(option, &e->flags.opt);
		*str += 1;
	}
}

void	get_width(char **str, t_env *e)
{
	e->flags.width = ft_atoi(*str);
	while (ft_isdigit(**str) && **str)
		*str += 1;
}

void	get_precis(char **str, t_env *e)
{
//		for floating numbers
	e->flags.precis = ft_atoi(*str);
	while (ft_isdigit(**str) && **str)
		*str += 1;
}

void	get_conv(char **str, char *conv)
{
	*conv = (!*conv) ? is_conv(*str) : *conv;
	*str += 1;
}

void	get_values(char **ptr, t_env *e)
{
	get_opt(ptr, e);
	ft_isalpha(**ptr) ? get_size(ptr, e) : 0;
	ft_isdigit(**ptr) ? get_width(ptr, e) : 0;
	get_conv(ptr, &e->flags.conv);
}

void	print_str(char **str, t_env *e)
{
	int		i;

	i = 0;
	while (**str)
	{
		if (**str == '%')
		{
			*str += 1;
			get_values(str, e);
		}
		if (!**str)
			break ;
		e->output[i++] = **str;
		*str += 1;
	}
}

int		main(int ac, char **av)
{
	t_env		e;
	char		*ptr;

	if (ac != 2)
		return (0);
	ptr = av[1];
	ft_bzero(&e, sizeof(e));
	print_str(&ptr, &e);
#ifdef DEBUG
	printf("width |%d|\n", e.flags.width);
	printf("conv |%c|\n", e.flags.conv);
	printf("min |%c| hash |%c| sign |%c| decal |%c|\n",
		e.flags.opt.min, e.flags.opt.hash,
		e.flags.opt.sign, e.flags.opt.decal);
	printf("out |%s|\n", e.output);
#endif
	return (0);
}
