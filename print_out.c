#include "ft_printf.h"

void	init_params(t_env *e)
{
	e->cast.ll = 0;
	e->ucast.ll = 0;
	ft_bzero(&e->flags, sizeof(e->flags));
	e->cast_size = 0;
	e->cast_id = 0;
	e->cast_sign = 0;
}

void	print_output(char *conv, int *i,
		t_env *e)
{
	(conv) ? ft_putstr(conv) : 0;
	(conv) ? ft_bzero(conv, *i) : 0;
	e->output_size += *i;
	*i = 0;
//	exit(1);
}

void	print_param(t_env *e, int *pos, char **str)
{
	void	(*conv)(t_env *, int *, char *);

	conv = e->conv[e->flags.conv];
	e->flags.opt.fill_prec = '0'; //precision filler
	conv(e, pos, e->out_tmp);
}


int		stock_perc(char **str, t_env *e, int *pos)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = *str;
	while (*ptr == '%')
	{
		e->out_tmp[i] = *ptr;
		ptr++;
		i++;
	}
	*pos += ft_strncpy_ret(&e->output[*pos], e->out_tmp, i / 2);
	*str += i;
	ft_bzero(e->out_tmp, i);
	if (i % 2 == 0 || !**str)
		return (0);
	return (1);
}

void	format_value(char *output, char **str, int *pos, t_env *e)
{
	int		ret;

	ret = stock_perc(str, e, pos);
	if (ret)
	{
		get_values(str, e, pos);
		if (e->flags.conv)
			print_param(e, pos, str);
		if (e->flags.conv != 'c')
			apply_opt(e, pos); // ???
		ft_strclr(e->out_tmp);
	}
	init_params(e);
}

void	print_str(char **str, t_env *e)
{
	int		i;
	int		perc;
	char	*ptr;

	i = 0;
	perc = 0;
	ptr = e->output;
	while (**str)
	{
		if (i == BUFF_SIZE)
			print_output(ptr, &i, e);
		while (**str == '%')
			format_value(ptr, str, &i, e);
		if (!**str)
			break ;
		e->output[i++] = **str;
		*str += 1;
	}
	e->output[i] = '\0';
	print_output(ptr, &i, e);
}
