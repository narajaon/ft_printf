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

void	get_values(char **ptr, t_env *e)
{
	*ptr += 1;
	//print output[5000]
	get_opt(ptr, e);
	is_cast(*ptr) ? get_size(ptr, e) : 0;
	ft_isdigit(**ptr) ? get_width(ptr, e) : 0;
	get_conv(ptr, &e->flags.conv);
}
