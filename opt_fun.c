#include "ft_printf.h"

void	minus_opt(t_env *e, int *pos, int size)
{
	int		i;

	i = e->flags.width - size;
	while (i-- > 0 )
	{
		e->output[*pos] = ' ';
		*pos += 1;
	}
}

void	width_opt(t_env *e, int *pos, int cast_size)
{
	int		i;
	int		posi;
	char	tmp[e->flags.width];

	i = e->flags.width - cast_size;
	posi = 0;
	if (i > 0)
	{
		while (posi < i )
			tmp[posi++] = ' ';
		ft_bzero(&tmp[posi], e->flags.width - posi);
		ft_putstr_ret(tmp, pos);
		*pos = cast_size;
		e->output_size += i;
	}
}

void	apply_sopt(t_env *e, int *pos, int cast_size)
{
	if (e->flags.opt.min && e->flags.width)
		minus_opt(e, pos, cast_size);
	else if (!e->flags.opt.min && e->flags.width)
		width_opt(e, pos, cast_size);
}

void	sign_opt(t_env *e, int *pos)
{
	if (e->flags.opt.sign == ' ')
		e->output[*pos++] = ' ';
	else if (e->flags.opt.sign == '+')
		e->output[*pos++] = '+';
}

void	zero_opt(t_env *e, int *pos)
{
}
