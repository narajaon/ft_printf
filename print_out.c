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
	ft_strclr(e->out_tmp);
}

int		stock_perc(char **str, t_env *e, int *pos)
{
	int		i;
	char	*ptr;

	//	ft_bzero(e->out_tmp, BUFF_SIZE);
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
	//STR(e->output);
	return (1);
}

void	format_value(char *output, char **str,
		int *pos, t_env *e)
{
	int		ret;

	ret = stock_perc(str, e, pos);
	print_output(output, pos, e);
	if (ret)
	{
		get_values(str, e, pos);
		if (e->flags.conv)
			get_param(e, pos);
		/*
		else
		{
			print_param(e, pos);
			apply_opt(e, pos);
			ft_strclr(e->out_tmp);
		}
		*/
	}
	//	STR(*str);
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
	print_output(ptr, &i, e);
}
