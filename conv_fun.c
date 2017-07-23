#include "ft_printf.h"

void	d_conv(t_env *e)
{
	ft_putnbr_ret(e->cast.d, &e->cast_size);
	e->output_size += e->cast_size;
}

void	capd_conv(t_env *e)
{
}

void	s_conv(t_env *e, int *pos)
{
	char	*arg;

	arg = va_arg(e->arg, char *);
	e->cast_size = ft_strlen(arg);
	if (e->cast_size >= BUFF_SIZE)
	{
		ft_putstr(arg);
		print_output((void *)0, &e->cast_size, e);
	}
	else
	{
		ft_strcpy(e->output, arg);
		*pos += e->cast_size;
	}
	apply_sopt(e, pos, e->cast_size);
}

void	caps_conv(t_env *e)
{
}

void	p_conv(t_env *e)
{
}

void	o_conv(t_env *e, int *pos)
{
	char	*str;

	str = &e->output[0];
	e->cast_size = ft_itoa_base(e->cast.d, str, 8);
	*pos = e->cast_size;
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
	e->cast.d = va_arg(e->arg, int);
	ft_putchar_ret(e->cast.d, &e->output_size);
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
