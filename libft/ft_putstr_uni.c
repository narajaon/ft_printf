#include "libft.h"

int			ft_putstr_uni(unsigned int *uni, char *str)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (uni[i])
		ret += ft_putuni_str(uni[i++], &str[ret]);
	return (ret);
}
