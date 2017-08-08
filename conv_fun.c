#include "ft_printf.h"

int		limits_1(t_env *e, int *pos, char *tmp)
{
	if (e->cast.ll + 1 == -9223372036854775807)
	{
		ft_strcpy(&e->output[*pos], "-9223372036854775808");
		e->cast_sign = 0;
		return (*pos += 20);
	}
	if (e->ucast.ll / 10 == 1844674407370955161)
	{
		if (e->flags.conv == 'o' || e->flags.conv == 'O')
		{
			ft_strcpy(tmp, "1777777777777777777777");
			*pos += 22;
		}
		else if (e->flags.conv == 'x' || e->flags.conv == 'X')
		{
			(e->flags.conv == 'x') ? ft_strcpy(tmp, "ffffffffffffffff") : 0;
			(e->flags.conv == 'X') ? ft_strcpy(tmp, "FFFFFFFFFFFFFFFF") : 0;
			*pos += 16;
		}
		else
		{
				ft_strcpy(tmp, "18446744073709551615");
			*pos += 20;
		}
		return (*pos);
	}
	return (0);
}

int		limits_2(t_env *e, int *pos, char *tmp)
{
	if (e->ucast.ll - 1 == 4294967294 &&
			(e->flags.conv == 'x' || e->flags.conv == 'X'))
	{
		if (e->cast_id == LL || e->cast_id == L ||
				e->cast_id == J || e->cast_id == Z)
		{
			(e->flags.conv == 'x') ? ft_strcpy(tmp, "ffffffffffffffff") : 0;
			(e->flags.conv == 'X') ? ft_strcpy(tmp, "FFFFFFFFFFFFFFFF") : 0;
			*pos += 16;
		}
		else
		{
			(e->flags.conv == 'x') ? ft_strcpy(tmp, "ffffffff") : 0;
			(e->flags.conv == 'X') ? ft_strcpy(tmp, "FFFFFFFF") : 0;
			*pos += 8;
		}
		return (*pos);
	}
	return (0);
}

int		limits_3(t_env *e, int *pos, char *tmp)
{
	if (e->ucast.ll / 10 == 1844674407370955161)
	{
		return (*pos += 20);
	}
	if (e->cast.ll / 10 == 922337203685477580 &&
			(e->flags.conv == 'd' || e->flags.conv == 'i'))
	{
		ft_strcpy(&e->output[*pos], "9223372036854775807");
		e->cast_sign = 0;
		return (*pos += 19);
	}
	return (0);
}

int		manage_limits(t_env *e, int *pos, char *tmp)
{
	if (limits_1(e, pos, tmp) || limits_2(e, pos, tmp) ||
			limits_3(e, pos, tmp))
		return (1);
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
	e->cast.ll = va_arg(e->arg, long long int);
	e->cast_sign = put_minus(e, pos, tmp);
	if (!manage_limits(e, pos, tmp))
	{
		if (e->cast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
			return ;
		e->cast.ll *= e->cast_sign;
		d_cst(e, pos, tmp);
	}
}

void	capd_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.ll = va_arg(e->arg, long long int);
	if (!manage_limits(e, pos, tmp))
	{
		if (e->flags.opt.sign == ' ' || e->flags.opt.sign == '+')
			*tmp++ = (e->flags.opt.sign == ' ') ? ' ' : '+';
		d_cst(e, pos, tmp);
		e->cast_size = e->cast_size + ((e->flags.opt.sign) ? 1 : 0);
	}
}

void	s_conv(t_env *e, int *pos, char *tmp)
{
	char	*arg;

	arg = va_arg(e->arg, char *);
	if (!arg)
	{
		ft_strcpy(&e->output[*pos], "(null)");
		*pos += 6;
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
	}
}

void	caps_conv(t_env *e, int *pos, char *tmp)
{
	wchar_t		*arg;

	arg = va_arg(e->arg, wchar_t *);
	if (!arg)
	{
		ft_strcpy(&e->output[*pos], "(null)");
		*pos += 6;
	}
}

void	p_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.ll = va_arg(e->arg, long long);
	if (e->cast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
		return ;
	e->cast_size = ft_ltoa_base(e->cast.l, tmp, 16);
}

void	o_conv(t_env *e, int *pos, char *tmp)
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.ll = va_arg(e->arg, long long int);
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	if (e->ucast.ll == 0 && e->flags.opt.precis &&
			!e->flags.precis && !e->flags.opt.hash)
		return ;
	if (!manage_limits(e, pos, tmp))
		oux_cst(e, pos, tmp, 8);
	else
	{
		ft_strcpy(&e->output[pos_tmp], tmp);
		ft_strclr(tmp);
	}
}

void	capo_conv(t_env *e, int *pos, char *tmp)
{
	e->ucast.ll = va_arg(e->arg, long long int);
	if (e->ucast.ll == 0 && e->flags.opt.precis &&
			!e->flags.precis && !e->flags.opt.hash)
		return ;
	if (!manage_limits(e, pos, tmp))
	{
		if (e->flags.opt.hash)
			hash_opt(e, pos);
		oux_cst(e, pos, tmp, 8);
	}
}

void	u_conv(t_env *e, int *pos, char *tmp)
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	if (e->ucast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
		return ;
	if (!manage_limits(e, pos, tmp))
		oux_cst(e, pos, tmp, 10);
	else
	{
		//		STR(tmp);
		ft_strcpy(&e->output[pos_tmp], tmp);
		ft_strclr(tmp);
	}
}

void	capu_conv(t_env *e, int *pos, char *tmp) //meme chose
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	if (!manage_limits(e, pos, tmp))
		oux_cst(e, pos, tmp, 10);
	else
	{
		ft_strcpy(&e->output[pos_tmp], tmp);
		ft_strclr(tmp);
	}
}

void	x_conv(t_env *e, int *pos, char *tmp)
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	if (e->ucast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
		return ;
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	if (!manage_limits(e, pos, tmp))
	{
		((e->ucast.d) ||
		 (!e->ucast.d && !e->flags.opt.hash))? oux_cst(e, pos, tmp, 16) : 0;
		if (!e->ucast.d && e->flags.opt.hash)
		{
			*tmp = '0';
			e->cast_size = 1;
		}
	}
	else
	{
		ft_strcpy(&e->output[pos_tmp], tmp);
		e->cast_size -= 1;
		ft_strclr(tmp);
	}
}

void	capx_conv(t_env *e, int *pos, char *tmp)
{
	int		pos_tmp;

	pos_tmp = *pos;
	e->ucast.d = va_arg(e->arg, long long int);
	if (e->ucast.ll == 0 && e->flags.opt.precis && !e->flags.precis)
		return ;
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	if (!manage_limits(e, pos, tmp))
	{
		if (e->cast_id == HH)
			e->cast_size = ft_cap_ltoa_base(e->ucast.hh, tmp, 16);
		else
			e->cast_size = ft_cap_ltoa_base(e->ucast.ll, tmp, 16);
	}
	else
	{
		ft_strcpy(&e->output[pos_tmp], tmp);
		e->cast_size -= 1;
		ft_strclr(tmp);
	}
}

void	print_null(t_env *e, int *pos, char *tmp)
{
	e->output_size += write(1, e->output, ft_strlen(e->output));
	ft_bzero(e->output, *pos);
	if (e->flags.width && !e->flags.opt.min)
	{
		while (--e->flags.width)
			e->output_size += write(1, " ", 1);
	}
	e->output_size += write(1, "\0", 1);
	*pos -= (*pos) ? 1 : 0;
	if (e->flags.width && e->flags.opt.min)
	{
		while (--e->flags.width)
			e->output_size += write(1, &e->flags.opt.fill_prec, 1);
	}
}

void	c_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.c = va_arg(e->arg, unsigned int);
	e->cast_size = 1;
	if (e->cast.c == '\0')
		print_null(e, pos, tmp);
	else
	{
		*tmp = e->cast.c;
		apply_opt(e, pos);
	}
}

void	capc_conv(t_env *e, int *pos, char *tmp)
{
	/*
	   e->cast.c = va_arg(e->arg, wint_t);
	   tmp[*pos] = e->cast.lc;
	   e->cast_size += 1;
	   */
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
