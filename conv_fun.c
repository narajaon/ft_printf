#include "ft_printf.h"

void	d_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.d = va_arg(e->arg, int);
	e->cast_size = ft_itoa_str(e->cast.d, tmp);
	e->cast_size = nbr_size(e->cast_size);
//	NBR(e->cast_size);
}

void	capd_conv(t_env *e)
{
}

void	s_conv(t_env *e, int *pos, char *tmp)
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
		ft_strcpy(tmp, arg);
}

void	caps_conv(t_env *e)
{
}

void	p_conv(t_env *e)
{
}

void	o_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.d = va_arg(e->arg, int);
	e->cast_size = ft_itoa_base(e->cast.d, tmp, 8);
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
void	x_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.d = va_arg(e->arg, int);
	e->cast_size = ft_itoa_base(e->cast.d, tmp, 16);
	*pos = e->cast_size;
}

void	capx_conv(t_env *e)
{
}

void	c_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.d = va_arg(e->arg, int);
	tmp[*pos] = e->cast.c;
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
