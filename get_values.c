#include "ft_printf.h"

void	get_width(char **str, t_env *e)
{
	e->flags.width = ft_atoi(*str);
	while (ft_isdigit(**str) && **str)
		*str += 1;
}

void	get_precis(char **str, t_env *e)
{
	//		for floating numbers
	e->flags.precis = ft_atoi(*str);
	while (ft_isdigit(**str) && **str)
		*str += 1;
}

void	get_values(char **ptr, t_env *e, int *pos)
{
//	*ptr += 1;
//	exit(STR(*ptr));
	while (**ptr && (is_opt(*ptr) || is_cast(*ptr) ||
			ft_isdigit(**ptr)))
	{
		get_opt(ptr, e);
		is_cast(*ptr) ? get_size(ptr, e, *ptr) : 0;
		ft_isdigit(**ptr) ? get_width(ptr, e) : 0;
	}
	if (**ptr == '\0') //attention debug
		exit(write(1, e->output, ft_strlen(e->output)));
//	if (**ptr == '%')
//		exit(STR(e->output));
//	exit(STR(*ptr));
	get_conv(ptr, e, pos);
}
