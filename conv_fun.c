#include "ft_printf.h"

void	d_conv(t_env *e, char c)
{
}

void	capd_conv(t_env *e, char c)
{
}

void	s_conv(t_env *e, char c)
{
}

void	caps_conv(t_env *e, char c)
{
}

void	p_conv(t_env *e, char c)
{
}

void	o_conv(t_env *e, char c)
{
}

void	capo_conv(t_env *e, char c)
{
}

void	u_conv(t_env *e, char c)
{
}

void	capu_conv(t_env *e, char c)
{
}
void	x_conv(t_env *e, char c)
{
}

void	capx_conv(t_env *e, char c)
{
}

void	c_conv(t_env *e, char c)
{
}

void	capc_conv(t_env *e, char c)
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
