#include "ft_printf.h"

int		manage_limits(t_env *e, int *pos)
{
	if (e->cast.ll + 1 == -9223372036854775807)
	{
		ft_strcpy(&e->output[*pos], "-9223372036854775808");
		return (*pos += 20);
	}
	if (e->ucast.ll - 1 == 9223372036854775806 &&
			(e->flags.conv == 'o' || e->flags.conv == 'O'))
	{
		ft_strcpy(&e->output[*pos], "777777777777777777777");
		return (*pos += 21);
	}
	if (e->ucast.ll / 10 == 1844674407370955161)
	{
		ft_strcpy(&e->output[*pos], "18446744073709551615");
		return (*pos += 20);
	}
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
	int		sign;

	e->cast.ll = va_arg(e->arg, long long int);
	e->cast_sign = put_minus(e, pos, tmp);
	if (!manage_limits(e, pos))
	{
		if (e->cast.d > 0)
		{
			if (e->flags.opt.sign == ' ' || e->flags.opt.sign == '+')
				*tmp++ = (e->flags.opt.sign == ' ') ? ' ' : '+';
		}
		e->cast.d *= e->cast_sign; // keep in mind for precis
		d_cst(e, pos, tmp);
		e->cast_size = e->cast_size + ((e->flags.opt.sign &&
					e->cast.d > 0) ? 1 : 0);
	}
}

void	capd_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.ll = va_arg(e->arg, long long int);
	if (!manage_limits(e, pos))
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
	e->flags.opt.fill_prec = ' ';
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
		write(1,"(null)", 6);
		e->output_size += 6;
		*pos = 0;
	}
}

void	p_conv(t_env *e, int *pos, char *tmp)
{
	*tmp++ = '0';
	*tmp++ = 'x';
	e->cast.ll = va_arg(e->arg, long long);
	e->cast_size = 2;
	e->cast_size += ft_ltoa_base(e->cast.l, tmp, 16);
}

void	o_conv(t_env *e, int *pos, char *tmp)
{
	e->ucast.ll = va_arg(e->arg, long long int);
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	oux_cst(e, pos, tmp, 8);
}

void	capo_conv(t_env *e, int *pos, char *tmp)
{
	e->ucast.ll = va_arg(e->arg, long long int);
	if (!manage_limits(e, pos))
	{
		if (e->flags.opt.hash)
			hash_opt(e, pos);
		oux_cst(e, pos, tmp, 8);
	}
}

void	u_conv(t_env *e, int *pos, char *tmp)
{
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	if (!manage_limits(e, pos))
		oux_cst(e, pos, tmp, 10);
}

void	capu_conv(t_env *e, int *pos, char *tmp) //meme chose
{
	e->ucast.ll = va_arg(e->arg, unsigned long long);
	if (!manage_limits(e, pos))
		oux_cst(e, pos, tmp, 10);
}

void	x_conv(t_env *e, int *pos, char *tmp)
{
	e->ucast.ll = va_arg(e->arg, long long int);
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	((e->ucast.d) ||
		(!e->ucast.d && !e->flags.opt.hash))? oux_cst(e, pos, tmp, 16) : 0;
	if (!e->ucast.d && e->flags.opt.hash)
	{
		*tmp = '0';
		e->cast_size = 1;
//		*pos += 1;
	//	STR(tmp);
	}
}

void	capx_conv(t_env *e, int *pos, char *tmp)
{
	e->ucast.d = va_arg(e->arg, long long int);
	if (e->flags.opt.hash)
		hash_opt(e, pos);
	e->cast_size = ft_cap_ltoa_base(e->ucast.ll, tmp, 16);
}

void	c_conv(t_env *e, int *pos, char *tmp)
{
	e->cast.c = va_arg(e->arg, unsigned int);
	//CHAR(e->cast.c);
	*tmp = e->cast.c;
	e->cast_size = 1;
	apply_opt(e, pos);
//	*pos += 1;
	//e->flags.opt.decal = ' ';
	ft_putstr(e->output);
	ft_strclr(e->out_tmp);
	ft_strclr(e->output);
//	NBR(e->cast_size);
	e->output_size += *pos;
	*pos = 0;
//	CHAR(e->cast.c);
//	exit(1);
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
