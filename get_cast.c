#include "ft_printf.h"

void	fill_cast(char *tmp, t_env *e)
{
	//get the appropriate cast / string
	printf("cast |%s|\n", tmp);
}

void	get_size(char **str, t_env *e)
{
	char		cast[3];
	char		*tmp;
	int			i;

	i = 0;
	tmp = cast;
	ft_bzero(tmp, 3);
	while (i < 2 && **str)
	{
		cast[i++] = **str;
		if (**str == 'j' || **str == 'z')
			break ;
		*str += 1;
	}
	if (is_cast(tmp))
		fill_cast(tmp, e);
}
