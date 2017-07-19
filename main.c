#include "ft_printf.h"

int		is_conv(char *str)
{
	if (*str == 's' || *str == 'S' || *str == 'p' || *str == 'd' ||
	*str == 'D' || *str == 'i' || *str == 'o' || *str == 'O' || *str == 'u' ||
	*str == 'U' || *str == 'x' || *str == 'X' || *str == 'c' || *str == 'C')
		return (*str);
	return (0);
}

int		is_cast(char *str)
{
	if (!ft_strcmp(str, "hh") || !ft_strcmp(str, "h") || !ft_strcmp(str, "l") ||
		!ft_strcmp(str, "ll") || !ft_strcmp(str, "j") || !ft_strcmp(str, "z"))
		return (1);
	return (0);
}

char	is_opt(char *str)
{
	if (*str == '-' || *str == '+' || *str == '#' ||
	*str == '0' || *str == ' ')
		return (*str);
	return (0);
}

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
	e->flags.precis = ft_atoi(*str);
	while (ft_isdigit(**str) && **str)
		*str += 1;
}

void	fill_cast(char *tmp, t_env *e)
{
}

void	get_size(char **str, t_env *e)
{
	char		cast[2];
	char		*tmp;
	int			i;

	i = 0;
	tmp = cast;
	while (i < 2 && *str)
	{
		cast[i++] = **str;
		*str += 1;
	}
	if (is_cast(tmp))
		fill_cast(tmp, e);
}

void	get_conv(char *str, t_env *e)
{
}

void	init_struct(t_env *e)
{
	ft_bzero(e, sizeof(*e));
}

int		main(int ac, char **av)
{
	t_env		e;
	char		*ptr;

	if (ac != 2)
		return (0);
	ptr = av[1];
	init_struct(&e);
	get_opt(&ptr, &e);
	printf("min |%c| hash |%c| sign |%c| decal |%c|\n", e.flags.opt.min,
	e.flags.opt.hash, e.flags.opt.sign, e.flags.opt.decal);
	get_width(&ptr, &e);
	printf("width %d\n", e.flags.width);
	return (0);
}
