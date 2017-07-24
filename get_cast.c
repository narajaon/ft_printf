#include "ft_printf.h"

int		cast_id(char *str)
{
	int		id;

	id = -1;
	if (!ft_strcmp(str, "hh"))
		id = HH;
	else if (!ft_strcmp(str, "z"))
		id = Z;
	else if (!ft_strcmp(str, "h"))
		id = H;
	else if (!ft_strcmp(str, "l"))
		id = L;
	else if (!ft_strcmp(str, "ll"))
		id = LL;
	else if (!ft_strcmp(str, "j"))
		id = J;
//	exit(NBR(id));
	return (id);
}

int		is_cast(char *src)
{
	char		str[2];
	int			i;

	i = 0;
	ft_bzero(str, 2);
	while (i < 2 && (*src == 'l' || *src == 'h' ||
				*src == 'j' || *src == 'z'))
	{
		str[i++] = *src;
		if (*src == 'j' || *src == 'z')
		{
			str[i] = '\0';
			break ;
		}
		src += 1;
	}
	str[i] = '\0';
//	exit(STR(str));
	if (!ft_strcmp(str, "hh") || !ft_strcmp(str, "h") ||
		!ft_strcmp(str, "l") || !ft_strcmp(str, "ll") ||
		!ft_strcmp(str, "j") || !ft_strcmp(str, "z"))
		return (cast_id(str));
	return (0);
}

void	get_size(char **str, t_env *e, char *ptr)
{
	if ((e->cast_id = is_cast(*str)) >= 0)
		*str += (e->cast_id == LL || e->cast_id == HH) ? 2 : 1;
}
