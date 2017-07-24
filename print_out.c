#include "ft_printf.h"

void	print_output(char *conv, int *i,
		t_env *e)
{
	(conv) ? ft_putstr(conv) : 0;
	(conv) ? ft_bzero(conv, *i) : 0;
	e->output_size += *i;
	*i = 0;
}

void	print_param(t_env *e, int *pos)
{
	void	(*conv)(t_env *, int *, char *);

	conv = e->conv[e->flags.conv];
	conv(e, pos, e->out_tmp);
}

void	get_param(t_env *e, int *pos)
{
	print_param(e, pos);
	apply_opt(e, pos);
}

void	format_value(char *output, char **str,
			int *pos, t_env *e)
{
	print_output(output, pos, e);
	get_values(str, e);
	get_param(e, pos);
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
