//#include "../ft_printf.h"

#include "libft.h"
#include <unistd.h>

typedef union		u_uni
{
	unsigned int	dec;
	unsigned char	oct_4[4];
	unsigned char	oct_3[3];
	unsigned char	oct_2[2];
	unsigned char	oct_1;
}					t_uni;

#include <stdio.h>
#include <locale.h>

// 11 110000

static int		uni_to_str(unsigned char *uni, char *str, int uni_id)
{
	int		ret;

	ret = 0;
	while (ret < uni_id)
	{
		str[ret] = uni[ret];
		ret++;
	}
	return (ret);
}

int				ft_putuni_str(unsigned int uni, char *str)
{
	t_uni			u8;
	unsigned char	c;
	int				ret;

	u8.dec = uni;
	ret = 0;
	if (uni > 0xFFFF)
	{
		c = (uni >> 18 & (~0x1FFFC0)) | 0xF0;
		u8.oct_4[0] = c;
		c = ((uni >> 12) & (~0x1FFFC0)) | 0x80;
		u8.oct_4[1] = c;
		c = ((uni >> 6) & (~0x1FFFC0)) | 0x80;
		u8.oct_4[2] = c;
		c = (uni & (~0x1FFFC0)) | 0x80;
		u8.oct_4[3] = c;
		ret = uni_to_str(u8.oct_4, str, 4);
	}
	else if (uni > 0x7FF)
	{
		c = (uni >> 12) | 0xE0;
		u8.oct_3[0] = c;
		c = ((uni >> 6) & (~0x3C0)) | 0x80;
		u8.oct_3[1] = c;
		c = (uni & (~0xFFC0)) | 0x80;
		u8.oct_3[2] = c;
		ret = uni_to_str(u8.oct_3, str, 3);
	}
	else if (uni > 0x7F)
	{
		c = (uni >> 6) | 0xC0;
		u8.oct_2[0] = c;
		c = (uni & (~0xFC0)) | 0x80;
		u8.oct_2[1] = c;
		ret = uni_to_str(u8.oct_2, str, 2);
	}
	else
		ret = uni_to_str(&u8.oct_1, str, 1);
	return (ret);
}

#define VALUE 0x1D320

/*
int		main()
{
	char			bin[300];

	ft_bzero(bin, 300);
	setlocale(LC_ALL, "");
	ft_putuni_str(VALUE, bin);
	printf("%s\n", bin);
	printf("\n%C\n", VALUE);
	//printf("%d\n", 0xF0 >> 3); //30
	//printf("%d\n", 0xE0 >> 4); //14
	//printf("%d\n", 0xC0 >> 5); //6
	return (0);
}*/
