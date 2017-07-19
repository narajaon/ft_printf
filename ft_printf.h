#ifndef FT_PRINTF
#define FT_PRINTF

#define DEBUG

#include "libft/libft.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

typedef union		u_cast
{
	int				d;
	short int		h;
	signed char		hh;
	char			c;
	long int		l;
	long long int	ll;
	float			f;
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
	char			conv;
}					t_flags;

typedef struct		s_env
{
	t_cast			cast;
	t_flags			flags;
}					t_env;


char	is_conv(char *str);
int		is_cast(char *str);
char	is_opt(char *str);


void	get_size(char **str, t_env *e);
#endif
