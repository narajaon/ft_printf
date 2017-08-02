#ifndef FT_PRINTF
#define FT_PRINTF
#define DEBUG
#define BUFF_SIZE 256

#include "libft/libft.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>
#include <limits.h>
#include <wchar.h>

#define Z 1
#define H 2
#define L 3
#define LL 4
#define J 5
#define HH 6

#define STR(x) printf(#x " = |%s|\n", x)
#define NBR(x) printf(#x " = |%d|\n", x)
#define CHAR(x) printf(#x " = |%c|\n", x)

typedef union		u_cast
{
	int				d;
	unsigned int	u;
	short			h;
	signed char		hh;
	char			c;
	long int		l;
	long long int	ll;
	float			f;
	size_t			z;
	intmax_t		j;
	wint_t			lc;
}					t_cast;

typedef union		u_ucast
{
	unsigned int			d;
	unsigned short			h;
	unsigned char			hh;
	unsigned long int		l;
	unsigned long long int	ll;
	size_t					z;
	uintmax_t				j;
}					t_ucast;

typedef struct		s_opt
{
	char			min;
	char			hash;
	char			sign;
	char			decal;
	char			fill_prec;
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
	t_ucast			ucast;
	t_flags			flags;
	va_list			arg;
	void			*conv[128];
	char			output[BUFF_SIZE];
	char			out_tmp[64];
	int				output_size; //strings
	int				cast_size; //numbers
	int				cast_id;
	int				cast_sign;
}					t_env;

char	is_conv(char c);
int		is_cast(char *str);
char	is_opt(char *str);

void	get_size(char **str, t_env *e, char *ptr);
void	get_opt(char **str, t_env *e);
void	get_conv(char **str, t_env *e, int *pos);
void	get_values(char **ptr, t_env *e, int *pos);
int		get_value_size(long long int value);

void	print_str(char **str, t_env *e);
void	print_output(char *conv, int *i,
		t_env *e);

void	d_conv(t_env *e, int *pos, char *tmp);
void	capd_conv(t_env *e, int *pos, char *tmp);
void	s_conv(t_env *e, int *pos, char *tmp);
void	caps_conv(t_env *e, int *pos, char *tmp);
void	p_conv(t_env *e, int *pos, char *tmp);
void	i_conv(t_env *e);
void	o_conv(t_env *e, int *pos, char *tmp);
void	capo_conv(t_env *e, int *pos, char *tmp);
void	u_conv(t_env *e, int *pos, char *tmp);
void	capu_conv(t_env *e, int *pos, char *tmp);
void	x_conv(t_env *e, int *pos, char *tmp);
void	capx_conv(t_env *e, int *pos, char *tmp);
void	c_conv(t_env *e, int *pos, char *tmp);
void	capc_conv(t_env *e, int *pos, char *tmp);

void	d_cst(t_env *e, int *pos, char *tmp);
void	oux_cst(t_env *e, int *pos, char *tmp, int base);

void	minus_opt(t_env *e, int *pos);
void	apply_opt(t_env *e, int *pos);
void	hash_opt(t_env *e, int *pos);

void	fill_funtab(t_env *e);

int		ft_printf(const char *str,...);
#endif
