#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdio.h>
#include "libft/libft.h"

typedef union		u_cast
{
	short char		h;
	short int		hh;
	long int		l;
	long long int	ll;
	size_t			z;
	intmax_t		j;
}					t_cast;

typedef struct		s_opt
{
	char			min;
	char			hash;
	char			sign;
	char			decal;
}					t_opt;

typedef struct		s_flags
{
	t_opt			opt;
	int				width;
	int				precis;
	int				size;
}					t_flags;

typedef struct		s_env
{
	t_cast			cast;
	t_flags			flags;
}					t_env;

#endif
