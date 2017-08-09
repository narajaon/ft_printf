#include "ft_printf.h"

void	get_width(char **str, t_env *e)
{
	e->flags.width = ft_atoi(*str);
	while (ft_isdigit(**str) && **str)
		*str += 1;
}

void	get_precis(char **str, t_env *e)
{
	*str += 1;
	e->flags.opt.precis = 1;
	e->flags.precis = ft_atoi(*str);
	while (ft_isdigit(**str) && **str)
		*str += 1;
}

int		get_values(char **ptr, t_env *e, int *pos)
{
	while (**ptr && (is_opt(*ptr) || is_cast(*ptr) ||
			ft_isdigit(**ptr) || **ptr == '.'))
	{
		get_opt(ptr, e);
		(**ptr == '.') ? get_precis(ptr, e) : 0;
		is_cast(*ptr) ? get_size(ptr, e, *ptr) : 0;
		ft_isdigit(**ptr) ? get_width(ptr, e) : 0;
	}
	if (**ptr == '\0') //attention debug
		exit(write(1, e->output, ft_strlen(e->output)));
	if (!is_conv(**ptr))
	{
		e->out_tmp[0] = **ptr;
		e->cast_size = 1;
		*ptr += 1;
		return (1);
	}
	get_conv(ptr, e, pos);
	return (1);
}
