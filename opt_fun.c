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

void	apply_precis_wid(t_env *e, int *pos, int *posi, int prec_pad)
{
	if (e->cast_sign < 0)
	{
		e->output[*pos + *posi] = '-';
		*pos += 1;
	}
	while (*posi < prec_pad)
	{
		e->output[*pos + *posi] = e->flags.opt.fill_prec;
		*posi += 1;
	}
	if (e->flags.conv == 's')
	{
		e->out_tmp[e->flags.precis] = '\0';
		e->cast_size = (e->cast_size > e->flags.precis) ?
			e->flags.precis : e->cast_size;
	//	STR(e->out_tmp);
	}
	//	CHAR(e->flags.opt.fill_prec);
	//	NBR(*posi);
	//	NBR(prec_pad);
	//	exit(1);
}

void	width_opt(t_env *e, int *pos)
{
	int		posi;
	int		prec_pad;
	int		wid_pad;

	posi = 0;
	prec_pad = e->flags.precis - e->cast_size;
	prec_pad = (prec_pad > 0) ? prec_pad : 0;
	prec_pad = (prec_pad > 0 && e->flags.conv == 's') ? 0 : prec_pad;
	wid_pad = e->flags.width - (e->cast_size + prec_pad);
	wid_pad = (wid_pad > 0) ? wid_pad : 0;
	//	NBR(prec_pad);
	prec_pad += wid_pad;
	//	NBR(wid_pad);
	//	NBR(posi);
	if (wid_pad > 0 || prec_pad > 0)
	{
		while (posi < wid_pad)
			e->output[*pos + posi++] = e->flags.opt.decal;
		apply_precis_wid(e, pos, &posi, prec_pad);
		ft_strcpy(&e->output[*pos + posi], e->out_tmp);
		*pos += e->cast_size + posi;
	}
	else
	{
		if (e->cast_sign < 0)
		{
			e->output[*pos + posi] = '-';
			*pos += 1;
		}
		apply_precis_wid(e, pos, &posi, prec_pad);
		ft_strcpy(&e->output[*pos], e->out_tmp);
		*pos += e->cast_size - ((e->cast_sign < 0) ? 1 : 0);
	}
	e->flags.width = 0;
	e->flags.opt.min = 0;
}

void	sign_opt(t_env *e, int *pos)
{
	if (e->flags.opt.sign && e->flags.width > e->cast_size)
	{
		e->output[*pos] = e->flags.opt.sign;
		*pos += 1;
		e->flags.width -= 1;
	}
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
	else if ((e->flags.width && !e->flags.opt.min) || e->flags.precis)
		width_opt(e, pos);
	else
	{
		ft_strcpy(&e->output[*pos], e->out_tmp);
		*pos += e->cast_size;
	}
}
