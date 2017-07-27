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

void	width_opt(t_env *e, int *pos)
{
	int		i;
	int		posi;

	i = e->flags.width - e->cast_size;
	posi = 0;
	if (i > 0)
	{
		while (posi < i )
			e->output[*pos + posi++] = e->flags.opt.decal;
		ft_strcpy(&e->output[*pos + posi], e->out_tmp);
		*pos += e->cast_size + posi;
		//		exit(NBR(ft_strlen(e->output)));
	}
	else
	{
		ft_strcpy(e->output, e->out_tmp);
		*pos += e->cast_size;
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
	else if (e->flags.width && !e->flags.opt.min)
		width_opt(e, pos);
	else
	{
		ft_strcpy(&e->output[*pos], e->out_tmp);
		*pos += e->cast_size;
	}
}
