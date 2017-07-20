#include "ft_printf.h"

int		is_cast(char *src)
{
	char		str[2];
	int			i;

	i = 0;
	ft_bzero(str, 2);
	while (i < 2 && *str)
	{
		str[i++] = *src;
		if (*src == 'j' || *src == 'z')
			break ;
		*src += 1;
	}
	if (!ft_strcmp(str, "hh") || !ft_strcmp(str, "h") ||
		!ft_strcmp(str, "l") || !ft_strcmp(str, "ll") ||
		!ft_strcmp(str, "j") || !ft_strcmp(str, "z"))
		return (1);
	return (0);
}

void	get_size(char **str, t_env *e)
{
	if (is_cast(*str))
	//put value in the proper union
		;
}
