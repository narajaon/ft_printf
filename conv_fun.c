#include "ft_printf.h"

void	d_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.ll = va_arg(e->arg, long long int);
	//e->ucast.ll = e->cast.ll;
	if (e->flags.opt.sign == ' ' || e->flags.opt.sign == '+')
		*tmp++ = (e->flags.opt.sign == ' ') ? ' ' : '+';
	d_cst(e, pos, tmp);
	e->cast_size = e->cast_size + ((e->flags.opt.sign) ? 1 : 0);
}

void	capd_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.ll = va_arg(e->arg, long long int);
	//e->ucast.ll = e->cast.ll;
	if (e->flags.opt.sign == ' ' || e->flags.opt.sign == '+')
		*tmp++ = (e->flags.opt.sign == ' ') ? ' ' : '+';
	d_cst(e, pos, tmp);
	e->cast_size = e->cast_size + ((e->flags.opt.sign) ? 1 : 0);
}

void	s_conv(t_env *e, int *pos, char *tmp)
{
	char	*arg;

	arg = va_arg(e->arg, char *);
	if (!arg)
	{
		write(1,"(null)", 6);
		e->output_size += 6;
		*pos = 0;
	}
	else
	{
		e->cast_size = ft_strlen(arg);
		if (e->cast_size >= BUFF_SIZE || !arg)
		{
			ft_putstr(arg);
			print_output((void *)0, &e->cast_size, e);
		}
		else
			ft_strcpy(tmp, arg);
//		STR(tmp);
	}
}

void	caps_conv(t_env *e)
{
	wchar_t		*arg;

	/*
	   arg = va_arg(e->arg, wchar_t *);
	   e->cast_size = ft_strlen(arg);
	   if (e->cast_size >= BUFF_SIZE)
	   {
	   ft_putstr(arg);
	   print_output((void *)0, &e->cast_size, e);
	   }
	   else
	   ft_strcpy(tmp, arg);
	   */
}

void	p_conv(t_env *e, int *pos, char *tmp)
{
	hash_opt(e, pos);
	e->cast.ll = va_arg(e->arg, long long);
	e->cast_size = (e->cast.ll) ? 0 : 1;
	e->cast_size += ft_ltoa_base(e->cast.l, tmp, 16);
}

void	o_conv(t_env *e, int *pos, char *tmp)
{
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	e->ucast.ll = va_arg(e->arg, long long int);
	oux_cst(e, pos, tmp, 8);
}

void	capo_conv(t_env *e, int *pos, char *tmp)
{
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	e->ucast.ll = va_arg(e->arg, long long int);
	oux_cst(e, pos, tmp, 8);
}

void	u_conv(t_env *e, int *pos, char *tmp)
{
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	oux_cst(e, pos, tmp, 10);
}

void	capu_conv(t_env *e, int *pos, char *tmp) //meme chose
{
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	oux_cst(e, pos, tmp, 10);
}

void	x_conv(t_env *e, int *pos, char *tmp)
{
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	e->ucast.ll = va_arg(e->arg, long long int);
	oux_cst(e, pos, tmp, 16);
}

void	capx_conv(t_env *e, int *pos, char *tmp)
{
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	e->cast.d = va_arg(e->arg, long long int);
	e->cast_size = ft_cap_ltoa_base(e->cast.ll, tmp, 16);
}

void	c_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.c = va_arg(e->arg, int);
	tmp[*pos] = e->cast.c;
	e->cast_size = 1;
}

void	capc_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.c = va_arg(e->arg, wint_t);
	tmp[*pos] = e->cast.lc;
	e->cast_size = 1;
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
