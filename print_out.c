#include "ft_printf.h"

void	print_output(char *conv, int *i,
		t_env *e)
{
	ft_putstr(conv);
	ft_bzero(conv, *i);
//	ft_bzero(&e->flags, sizeof(e->flags));
	e->output_size += *i;
	*i = 0;
}

void	print_param(t_env *e)
{
	void	(*conv)(t_env *);

	conv = e->conv[e->flags.conv];
	conv(e);
}

void	print_param_str(t_env *e, int *pos)
{
	void	(*conv)(t_env *, int *);

	conv = e->conv['s'];
	conv(e, pos);
}

void	get_param(t_env *e, int *pos)
{
	if (e->flags.conv == 's')
		print_param_str(e, pos);
	else
		e->cast.ll = va_arg(e->arg, long long int);
}

void	format_value(char *output, char **str,
		int *pos, t_env *e)
{
	print_output(output, pos, e);
	get_values(str, e);
	get_param(e, pos);
	print_param(e);
}

void	print_str(char **str, t_env *e)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = e->output;
	while (**str)
	{
		if (i == BUFF_SIZE)
			print_output(ptr, &i, e);
		if (**str == '%')
			format_value(ptr, str, &i, e);
		if (!**str)
			break ;
		e->output[i++] = **str;
		*str += 1;
	}
	print_output(ptr, &i, e);
}
