#include "ft_printf.h"

void	minus_opt(t_env *e, int *pos)
{
	int		i;
	int		prec_pad;

	prec_pad = (e->cast_size < e->flags.precis) ?
		e->flags.precis - e->cast_size : 0;
	i = e->flags.width - (prec_pad + e->cast_size);
	if ((e->cast_sign > 0 && e->flags.opt.sign) || e->cast_sign < 0)
	{
		e->output[*pos] = (e->cast_sign < 0) ? '-' : e->flags.opt.sign;
		*pos += 1;
		i -= (e->cast_sign < 0) ? 0 : 1;
	}
	while (prec_pad-- > 0)
	{
		e->output[*pos] = '0';
		*pos += 1;
	}
	ft_strcpy(&e->output[*pos], e->out_tmp);
	*pos += e->cast_size;
	while (i-- > 0 )
	{
		e->output[*pos] = ' ';
		*pos += 1;
	}
}

void	init_prec_wid_str(t_env *e, int *prec_pad, int *wid_pad)
{
	int		cast;

	cast = (e->cast_size > e->flags.precis) ?
		e->cast_size : e->flags.precis;
	*prec_pad = (e->cast_size < e->flags.precis || !e->flags.opt.precis) ?
		e->cast_size : e->flags.precis;
	*wid_pad = e->flags.width - *prec_pad;
	*wid_pad = (*wid_pad > 0) ? *wid_pad : 0;
}

void	init_prec_wid_digit(t_env *e, int *prec_pad, int *wid_pad)
{
	*prec_pad = (e->flags.precis > e->cast_size) ?
		e->flags.precis - e->cast_size : 0;
	if (e->flags.conv == 'p')
		*prec_pad += 2;
	*wid_pad = e->flags.width - (e->cast_size + *prec_pad);
	if (e->flags.opt.sign && e->cast_sign > 0)
		*wid_pad -= 1;
	*wid_pad = (*wid_pad > 0) ? *wid_pad : 0;
	if (e->flags.conv == 'p')
		*prec_pad -= 2;
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
		*pos += prec_pad + posi;
	}
	else
	{
		ft_strncpy(&e->output[*pos], e->out_tmp, prec_pad);
		*pos += prec_pad - posi;
	}
}

void	put_sign(t_env *e, int *pos, int *posi)
{
	if (e->flags.opt.sign && e->cast_sign > 0 && e->flags.opt.decal == ' ')
	{
		e->output[*pos + *posi] = e->flags.opt.sign;
		*pos += 1;
	}
	else if (e->cast_sign < 0 && e->flags.opt.decal == ' ')
	{
		e->output[*pos + *posi] = '-';
		*pos += 1;
	}
	else if (e->flags.conv == 'p')
	{
		e->output[*pos + *posi] = '0';
		*pos += 1;
		e->output[*pos + *posi] = 'x';
		*pos += 1;
	}
}

void	width_opt_digit(t_env *e, int *pos)
{
	int		posi;
	int		prec_pad;
	int		wid_pad;

	posi = 0;
	init_prec_wid_digit(e, &prec_pad, &wid_pad);
	while (posi < wid_pad)
		e->output[*pos + posi++] = e->flags.opt.decal;
	put_sign(e, pos, &posi);
	if (wid_pad > 0 || prec_pad > 0)
	{
		while (posi < prec_pad)
			e->output[*pos + posi++] = e->flags.opt.fill_prec;
		ft_strcpy(&e->output[*pos + posi], e->out_tmp);
		*pos += posi + e->cast_size;
	}
	else
	{
		ft_strcpy(&e->output[*pos + posi], e->out_tmp);
		*pos += e->cast_size;
	}
	//NBR(prec_pad);
	//NBR(wid_pad);
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
	if (e->flags.opt.decal == '0' &&
			(e->cast_sign < 0 || e->flags.opt.sign))
	{
			e->output[*pos] = (e->cast_sign < 0) ? '-' : e->flags.opt.sign;
		*pos += 1;
	}
	if (e->flags.width && e->flags.opt.min)
		minus_opt(e, pos);
	else if (e->flags.conv == 's' || e->flags.conv == 'c')
		width_opt_str(e, pos);
	else
		width_opt_digit(e, pos);
}
