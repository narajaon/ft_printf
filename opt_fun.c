#include "ft_printf.h"

void	minus_opt(char *str, t_env *e, int *pos)
{
	int		i;

	i = 0;
	while (*str)
	{
		e->output[*pos++] = *str++;
		e->flags.width--;
		i++;
	}
	while (i++ < e->flags.width)
		e->output[*pos++] = ' ';
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
