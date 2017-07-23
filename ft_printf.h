#ifndef FT_PRINTF
#define FT_PRINTF
#define DEBUG
#define BUFF_SIZE 10

#include "libft/libft.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>


#define STR(x) printf(#x " = %s\n", x)
#define NBR(x) printf(#x " = %d\n", x)
#define CHAR(x) printf(#x " = %c\n", x)

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
	va_list			arg;
	void*			conv[128];
	char			output[BUFF_SIZE];
	int				output_size; //strings
	int				cast_size; //numbers
}					t_env;

char	is_conv(char c);
int		is_cast(char *str);
char	is_opt(char *str);

void	get_size(char **str, t_env *e);
void	get_opt(char **str, t_env *e);
void	get_conv(char **str, char *conv);
void	get_values(char **ptr, t_env *e);
int		get_value_size(long long int value);

void	print_str(char **str, t_env *e);
void	print_output(char *conv, int *i,
		t_env *e);

void	d_conv(t_env *e);
void	capd_conv(t_env *e);
void	s_conv(t_env *e, int *pos);
void	caps_conv(t_env *e);
void	p_conv(t_env *e);
void	i_conv(t_env *e);
void	o_conv(t_env *e);
void	capo_conv(t_env *e);
void	u_conv(t_env *e);
void	capu_conv(t_env *e);
void	x_conv(t_env *e);
void	capx_conv(t_env *e);
void	c_conv(t_env *e);
void	capc_conv(t_env *e);

void	fill_funtab(t_env *e);

#endif
