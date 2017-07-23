#include "ft_printf.h"

void	d_conv(t_env *e)
{
	ft_putnbr_ret(e->cast.d, &e->output_size);
}

void	capd_conv(t_env *e)
{
}

void	s_conv(t_env *e, int *pos)
{
	char	*arg;
	int		out_len;

	arg = va_arg(e->arg, char *);
	out_len = ft_strlen(arg);
	if (out_len >= BUFF_SIZE)
	{
		ft_putstr(arg);
		print_output((void *)0, &out_len, e);
	}
	else
	{
		ft_strcpy(e->output, arg);
		*pos += out_len;
	}
}

void	caps_conv(t_env *e)
{
}

void	p_conv(t_env *e)
{
}

void	o_conv(t_env *e)
{
}

void	capo_conv(t_env *e)
{
}

void	u_conv(t_env *e)
{
}

void	capu_conv(t_env *e)
{
}
void	x_conv(t_env *e)
{
}

void	capx_conv(t_env *e)
{
}

void	c_conv(t_env *e)
{
	int		c;

	c = va_arg(e->arg, int);
	ft_putchar_ret(c, &e->output_size);
}

void	capc_conv(t_env *e)
{
}

void	fill_funtab(t_env *e)
{
	e->conv['d'] = &d_conv;
	e->conv['D'] = &capd_conv;
	e->conv['i'] = &d_conv;
	e->conv['s'] = &s_conv;
	e->conv['S'] = &caps_conv;
	e->conv['p'] = &p_conv;
	e->conv['o'] = &o_conv;
	e->conv['O'] = &capo_conv;
	e->conv['u'] = &u_conv;
	e->conv['U'] = &capu_conv;
	e->conv['x'] = &x_conv;
	e->conv['X'] = &capx_conv;
	e->conv['c'] = &c_conv;
	e->conv['C'] = &capc_conv;
}
