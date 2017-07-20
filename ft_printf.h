#ifndef FT_PRINTF
#define FT_PRINTF

#define DEBUG
#define BUFF_SIZE 5000

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
	void*			conv[128];
	char			output[BUFF_SIZE];
	va_list			arg;
}					t_env;

char	is_conv(char c);
int		is_cast(char *str);
char	is_opt(char *str);

void	get_size(char **str, t_env *e);
void	get_opt(char **str, t_env *e);
void	get_conv(char **str, char *conv);

void	print_str(char **str, t_env *e);
void	d_conv(t_env *e, char c);
void	capd_conv(t_env *e, char c);
void	s_conv(t_env *e, char c);
void	caps_conv(t_env *e, char c);
void	p_conv(t_env *e, char c);
void	i_conv(t_env *e, char c);
void	o_conv(t_env *e, char c);
void	capo_conv(t_env *e, char c);
void	u_conv(t_env *e, char c);
void	capu_conv(t_env *e, char c);
void	x_conv(t_env *e, char c);
void	capx_conv(t_env *e, char c);
void	c_conv(t_env *e, char c);
void	capc_conv(t_env *e, char c);

void	fill_funtab(t_env *e);

#endif
