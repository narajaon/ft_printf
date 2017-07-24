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
			e->output[*pos + posi++] = ' ';
		ft_strcpy(&e->output[*pos + posi], e->out_tmp);
		*pos += e->cast_size + posi;
	}
	else
	{
		ft_strcpy(e->output, e->out_tmp);
		*pos += e->cast_size;
	}
	e->flags.width = 0;
	e->flags.opt.min = 0;
}

void	zero_opt(t_env *e, int *pos)
{
}

void	apply_opt(t_env *e, int *pos)
{
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
