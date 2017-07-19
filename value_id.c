#include "ft_printf.h"

char	is_conv(char *str)
{
	if (*str == 's' || *str == 'S' || *str == 'p' ||
		*str == 'd' || *str == 'D' || *str == 'i' ||
		*str == 'o' || *str == 'O' || *str == 'u' ||
		*str == 'U' || *str == 'x' || *str == 'X' ||
		*str == 'c' || *str == 'C')
		return (*str);
	return (0);
}

int		is_cast(char *str)
{
	if (!ft_strcmp(str, "hh") || !ft_strcmp(str, "h") ||
		!ft_strcmp(str, "l") || !ft_strcmp(str, "ll") ||
		!ft_strcmp(str, "j") || !ft_strcmp(str, "z"))
		return (1);
	return (0);
}

char	is_opt(char *str)
{
	if (*str == '-' || *str == '+' || *str == '#' ||
	*str == '0' || *str == ' ')
		return (*str);
	return (0);
}
