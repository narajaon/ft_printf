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

void	print_values(t_env *e)
{
}

void	print_output(char *conv, int *i)
{
	ft_putstr(conv);
	ft_bzero(conv, *i);
	*i = 0;
}

void	print_str(char **str, t_env *e)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = e->output;
	while (**str)
	{
		if (i == BUFF_SIZE)
			print_output(ptr, &i);
		if (**str == '%')
		{
			print_output(ptr, &i);
			get_values(str, e);
			print_values(e);
		}
		if (!**str)
			break ;
		e->output[i++] = **str;
		*str += 1;
	}
	print_output(ptr, &i);
}
