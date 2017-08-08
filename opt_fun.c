#include "ft_printf.h"

void	minus_opt(t_env *e, int *pos)
{
	int		i;

	i = e->flags.width - e->cast_size;
	ft_strcpy(&e->output[*pos], e->out_tmp);
	*pos += e->cast_size;
	while (i-- > 0 )
	{
		e->output[*pos] = ' ';
		*pos += 1;
	}
	e->flags.width = 0;
	e->flags.opt.min = 0;
}

void	apply_sign(t_env *e, int *wid_pad, int *prec_pad, int *pos)
{
	if (e->cast_sign < 0)
	{
		if (e->flags.opt.decal == '0')
			e->flags.opt.fill_prec = '-';
		else
			e->flags.opt.fill_prec = '-';
	}
	else if (e->cast_sign > 0 && e->flags.opt.sign)
		e->flags.opt.fill_prec = e->flags.opt.sign;
}

void	init_prec_wid_str(t_env *e, int *prec_pad, int *wid_pad)
{
	int		cast;

	cast = (e->cast_size > e->flags.precis) ?
		e->cast_size : e->flags.precis;
	*prec_pad = (e->cast_size < e->flags.precis || !e->flags.opt.precis) ?
		e->cast_size : e->flags.precis;
	*wid_pad = e->flags.width - *prec_pad;
	*wid_pad = (*wid_pad) ? *wid_pad : 0;
}


void	init_prec_wid_digit(t_env *e, int *prec_pad, int *wid_pad)
{
	*prec_pad = (e->flags.precis > e->cast_size) ?
		e->flags.precis - e->cast_size : 0;
	*wid_pad = e->flags.width - (e->cast_size + *prec_pad);
	*wid_pad = (*wid_pad > 0) ? *wid_pad : 0;
	*prec_pad += *wid_pad;
}

void	width_opt_str(t_env *e, int *pos)
{
	int		posi;
	int		prec_pad;
	int		wid_pad;

	posi = 0;
	init_prec_wid_str(e, &prec_pad, &wid_pad);
	if (wid_pad > 0 || prec_pad > 0)
	{
		while (posi < wid_pad)
			e->output[*pos + posi++] = e->flags.opt.decal;
		ft_strncpy(&e->output[*pos + posi], e->out_tmp, prec_pad);
		*pos += prec_pad + posi - ((!e->cast.c) ? 1 : 0);
	}
	else
	{
		ft_strncpy(&e->output[*pos], e->out_tmp, prec_pad);
		*pos += prec_pad - posi;
	}
}

void	width_opt_digit(t_env *e, int *pos)
{
	int		posi;
	int		prec_pad;
	int		wid_pad;

	posi = 0;
		//NBR(*pos);
	init_prec_wid_digit(e, &prec_pad, &wid_pad);
	if (wid_pad > 0 || prec_pad > 0)
	{
		while (posi < wid_pad)
			e->output[*pos + posi++] = e->flags.opt.decal;
		while (posi < prec_pad)
			e->output[*pos + posi++] = e->flags.opt.fill_prec;
		if (e->flags.opt.fill_prec == ' ')
		{
			e->output[*pos + posi++] = (e->cast_sign > 0) ?
				e->flags.opt.sign : '-';
		}
	//NBR(*pos);
		ft_strcpy(&e->output[*pos + posi], e->out_tmp);
		*pos += posi + e->cast_size; // pk -1 ????
		//STR(e->output);
	//	STR(e->out_tmp);
	}
	else
	{
		if (e->flags.opt.decal == ' ')
		{
			e->output[*pos] = (e->cast_sign > 0) ?
				e->flags.opt.sign : '-';
			*pos += 1;
		}
		while (posi < prec_pad)
			e->output[*pos + posi++] = e->flags.opt.fill_prec;
		ft_strcpy(&e->output[*pos], e->out_tmp);
		*pos += e->cast_size;
	}
	//NBR(wid_pad);
	//NBR(prec_pad);
}

void	sign_opt(t_env *e, int *pos)
{
	if (e->flags.opt.fill_prec == '0')
	{
		if (e->cast_sign > 0 && e->flags.opt.sign)
		{
			e->output[*pos] = e->flags.opt.sign;
			*pos += 1;
			//e->flags.width -= 1;
//			ICI
		}
		else if (e->cast_sign < 0)
		{
			e->output[*pos] = '-';
			*pos += 1;
		}
	}
//	NBR(e->flags.width);
//	NBR(e->cast_size);
//	CHAR(e->flags.opt.sign);
}

void	hash_opt(t_env *e, int *pos)
{
	if (e->ucast.ll != 0)
	{
		e->output[*pos] = '0';
		*pos += 1;
		if (e->flags.conv == 'x' || e->flags.conv == 'X')
		{
			e->output[*pos] = (e->flags.conv == 'X') ? 'X' : 'x';
			*pos += 1;
		}
	}
}

void	apply_opt(t_env *e, int *pos)
{
	sign_opt(e, pos);
	if (e->flags.width && e->flags.opt.min)
		minus_opt(e, pos);
	else if ((e->flags.width || e->flags.opt.precis) &&
			(e->flags.conv == 's' || e->flags.conv == 'c'))
		width_opt_str(e, pos);
	else if ((e->flags.width || e->flags.opt.precis || e->cast_sign < 0))
		width_opt_digit(e, pos);
	else
	{
		ft_strcpy(&e->output[*pos], e->out_tmp);
		if (!e->cast.ll && !e->ucast.ll && (e->flags.conv == 'o' ||
					e->flags.conv == 'u' || e->flags.conv == 'd'))
		{
			e->cast_size = 0;
			*pos += 1;
		}
		*pos += e->cast_size;
	}
}
