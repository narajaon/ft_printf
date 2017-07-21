#include "ft_printf.h"

void	d_conv(t_env *e)
{
	e->cast_size = get_value_size(abs(e->cast.d)) +
		((e->cast.d < 0) ? 1 : 0);
	e->output_size += e->cast_size;
	ft_putnbr(e->cast.d);
}

void	capd_conv(t_env *e)
{
}

void	s_conv(t_env *e, int *pos)
{
	char	*arg;

	arg = va_arg(e->arg, char *);
//	ft_strcpy(ptr, arg);
//	*pos += ft_strlen(arg);
	printf("arg %s\n",
		va_arg(e->arg, char *));
	e->flags.conv = 0;
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
