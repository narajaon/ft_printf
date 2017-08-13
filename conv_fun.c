#include "ft_printf.h"

int		d_limits(t_env *e, int *pos, char *tmp)
{
	if ((e->cast_id == H && e->cast.d == SHRT_MIN) ||
		(e->cast_id == HH && e->cast.d <= CHAR_MIN) ||
		(e->cast.l >= LONG_MAX || e->cast.l <= LONG_MIN) ||
		(e->cast.d > INT_MAX || e->cast.d <= INT_MIN) ||
		(e->cast.l == UINT_MAX))
	{
		e->cast.l *= -1;
		return (e->is_limit = 1);
	}
	return (e->is_limit = 0);
}

int		oux_limits(t_env *e, int *pos, char *tmp)
{
	if (e->cast_id == H && e->ucast.d == SHRT_MIN)
		return (e->is_limit = 1);
	if (e->cast_id == HH && e->ucast.d <= CHAR_MIN)
		return (e->is_limit = 1);
	return (0);
}

int		put_minus(t_env *e, int *pos, char *tmp)
{
	if (e->cast.d < 0 && e->flags.opt.decal)
	{
		e->flags.width--;
		return (-1);
	}
	return (1);
}

void	d_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.ll = va_arg(e->arg, long long);
	if (e->flags.opt.precis && e->flags.precis >= 0)
		e->flags.opt.decal = ' ';
	e->cast_sign = put_minus(e, pos, tmp);
	if ((e->cast.ll >= LLONG_MAX || e->cast.ll <= LLONG_MIN) &&
			(e->cast_id == L || e->cast_id == LL))
	{
		if (e->cast.ll >= LLONG_MAX)
			e->cast_sign = 1;
		else
			e->cast_sign = -1;
		e->cast_size = ft_ultoa_str(e->cast.ll, tmp);
		return ;
	}
	d_limits(e, pos, tmp);
	if (e->cast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
		return ;
	e->cast.ll *= e->cast_sign;
	d_cst(e, pos, tmp);
}

void	capd_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.ll = va_arg(e->arg, long long);
	if ((e->cast.ll >= LLONG_MAX || e->cast.ll <= LLONG_MIN))
	{
		if (e->cast.ll >= LLONG_MAX)
			e->cast_size = ft_ultoa_str(e->cast.ll, tmp);
		else
		{
			e->cast_sign = -1;
			e->cast_size = ft_ultoa_str(e->cast.ll, tmp);
		}
		return ;
	}
	if (e->flags.opt.sign == ' ' || e->flags.opt.sign == '+')
		*tmp++ = (e->flags.opt.sign == ' ') ? ' ' : '+';
	d_cst(e, pos, tmp);
	e->cast_size = e->cast_size + ((e->flags.opt.sign) ? 1 : 0);
}

void	manage_overflow(t_env *e, int *pos, char *tmp, char *arg)
{
	if (e->flags.opt.precis)
		e->cast_size = e->flags.precis;
	e->output_size += write(1, e->output, *pos);
	if (!e->flags.opt.min)
	{
		while (e->flags.width-- > e->cast_size)
			e->output_size += write(1, " ", 1);
	}
	e->output_size += write(1, arg, e->cast_size);
	if (e->flags.opt.min)
	{
		while (e->flags.width-- > e->cast_size)
			e->output_size += write(1, " ", 1);
	}
	ft_bzero(e->output, sizeof(e->output));
	e->overflow = 1;
	*pos = 0;
}

void	s_conv(t_env *e, int *pos, char *tmp)
{
	char	*arg;

	if (e->cast_id == L)
	{
		caps_conv(e, pos, tmp);
		return ;
	}
	arg = va_arg(e->arg, char *);
	if (!arg)
	{
		ft_strcpy(tmp, "(null)");
		e->cast_size = 6;
	}
	else
	{
		e->cast_size = ft_strlen(arg);
		if (e->cast_size >= BUFF_SIZE || !arg)
			manage_overflow(e, pos, tmp, arg);
		else
			ft_strcpy(tmp, arg);
	}
}

void	caps_conv(t_env *e, int *pos, char *tmp)
{
	unsigned int	*arg;

	arg = va_arg(e->arg, unsigned int *);
	if (!arg)
	{
		ft_strcpy(&e->output[*pos], "(null)");
		*pos += 6;
	}
	else
		e->cast_size = ft_putstr_uni(arg, tmp);
	e->flags.conv = 's';
}

void	p_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.ll = va_arg(e->arg, long long);
	e->flags.opt.sign = 'x';
	if (e->cast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
		return ;
	e->cast_size = ft_ltoa_base(e->cast.l, tmp, 16);
}

void	o_conv(t_env *e, int *pos, char *tmp)
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.ll = va_arg(e->arg, long long int);
	if ((e->flags.opt.hash && e->ucast.ll &&
			(e->flags.precis <= e->cast_size)) ||
			(e->flags.opt.hash && e->ucast.ll && !e->flags.opt.precis))
		e->flags.opt.sign = '0';
	else
		e->flags.opt.sign = 0;
	if (e->ucast.ll == 0 && e->flags.opt.precis &&
			!e->flags.precis && !e->flags.opt.hash)
		return ;
	oux_cst(e, pos, tmp, 8);
}

void	capo_conv(t_env *e, int *pos, char *tmp)
{
	e->ucast.ll = va_arg(e->arg, long long int);
	if (e->ucast.ll == 0 && e->flags.opt.precis &&
			!e->flags.precis && !e->flags.opt.hash)
		return ;
	if ((e->flags.opt.hash && e->ucast.ll &&
			(e->flags.precis <= e->cast_size)) ||
			(e->flags.opt.hash && e->ucast.ll && !e->flags.opt.precis))
		e->flags.opt.sign = '0';
	else
		e->flags.opt.sign = 0;
	oux_cst(e, pos, tmp, 8);
}

void	u_conv(t_env *e, int *pos, char *tmp)
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	e->flags.opt.sign = 0;
	if (e->ucast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
		return ;
	oux_cst(e, pos, tmp, 10);
}

void	capu_conv(t_env *e, int *pos, char *tmp)
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	e->flags.opt.sign = 0;
	oux_cst(e, pos, tmp, 10);
}

void	x_conv(t_env *e, int *pos, char *tmp)
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	if (e->ucast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
		return ;
	if (e->flags.opt.hash && e->ucast.ll)
	{
		e->flags.conv = 'p';
		e->flags.opt.sign = 'x';
	}
	else
		e->flags.opt.sign = 0;
	oux_cst(e, pos, tmp, 16);
	if (!e->ucast.d && e->flags.opt.hash)
	{
		*tmp = '0';
		e->cast_size = 1;
	}
}

void	capx_conv(t_env *e, int *pos, char *tmp)
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.ll = va_arg(e->arg, long long int);
	if (e->ucast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
		return ;
	if (e->flags.opt.hash && e->ucast.ll)
	{
		e->flags.conv = 'p';
		e->flags.opt.sign = 'X';
	}
	else
		e->flags.opt.sign = 0;
	if (e->cast_id == HH)
		e->cast_size = ft_cap_ultoa_base(e->ucast.hh, tmp, 16);
	else if (e->cast_id == L || e->cast_id == LL)
		e->cast_size = ft_cap_ultoa_base(e->ucast.ll, tmp, 16);
	else
		e->cast_size = ft_cap_ultoa_base(e->ucast.d, tmp, 16);
}

void	print_null(t_env *e, int *pos, char *tmp)
{
	print_output(e->output, pos, e);
	if (e->flags.width && !e->flags.opt.min)
	{
		while (--e->flags.width)
			e->output_size += write(1, &e->flags.opt.decal, 1);
	}
	e->output_size += write(1, "\0", 1);
	if (e->flags.width && e->flags.opt.min)
	{
		while (--e->flags.width)
			e->output_size += write(1, &e->flags.opt.fill_prec, 1);
	}
}

void	c_conv(t_env *e, int *pos, char *tmp)
{
	e->flags.opt.fill_prec = ' ';
	if (e->cast_id == L)
	{
		capc_conv(e, pos, tmp);
		return ;
	}
	if (!e->cast.c)
		e->cast.c = va_arg(e->arg, unsigned int);
	e->cast_size = 1;
	if (e->cast.c)
	{
		*tmp = e->cast.c;
		e->flags.precis = 1;
		apply_opt(e, pos);
	}
	else
		print_null(e, pos, tmp);
}

void	capc_conv(t_env *e, int *pos, char *tmp)
{
	e->ucast.d = va_arg(e->arg, unsigned int);
	if (e->ucast.d)
	{
		e->cast_size = ft_putuni_str(e->ucast.d, tmp);
		apply_opt(e, pos);
	}
	else
		print_null(e, pos, tmp);
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
