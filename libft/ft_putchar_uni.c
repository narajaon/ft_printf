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

// 1 01111 100001 110011

int		ft_putchar_uni(unsigned int uni)
{
	t_uni			u8;
	unsigned char	c;
	int				ret;
	char			bin[300];

	u8.dec = uni;
	ret = 0;
	ft_bzero(bin, 300);
	if (uni > 0xFFFF)
	{
		c = (uni >> 16) | 0xF0;
		u8.oct_3[0] = c;
		/*
		c = ((uni >> 12) & (~0x3C0)) | 0x80;
		u8.oct_3[1] = c;
		c = (uni & (~0xFFC0)) | 0x80;
		u8.oct_3[2] = c;
		*/
		//ret = write(1, u8.oct_3, 2);

		ft_itoa_base(c, bin, 2);
		printf("%s\n", bin);
		//printf("uni %d\n", uni);
		printf("\nid : 1\n");
	}
	else if (uni > 0x7FF)
	{
		c = (uni >> 12) | 0xE0;
		u8.oct_3[0] = c;
		c = ((uni >> 6) & (~0x3C0)) | 0x80;
		u8.oct_3[1] = c;
		c = (uni & (~0xFFC0)) | 0x80;
		u8.oct_3[2] = c;
		ret = write(1, u8.oct_3, 2);
		printf("\nid : 2\n");
	}
	else if (uni > 0x7F)
	{
		c = (uni >> 6) | 0xC4;
		u8.oct_2[0] = c;
		c = (uni & (~0xFF00)) | 0x80;
		u8.oct_2[1] = c;
		ret = write(1, u8.oct_2, 3);
		printf("\nid : 3\n");
	}
	else
		ret = write(1, &u8.oct_1, 1);
	return (ret);
}

#define VALUE 0x2F873

int		main()
{
	setlocale(LC_ALL, "");
	ft_putchar_uni(VALUE);
	printf("\n%C\n", VALUE);
	//printf("%d\n", 0xF0 >> 3); //30
	//printf("%d\n", 0xE0 >> 4); //14
	//printf("%d\n", 0xC0 >> 5); //6
	return (0);
}
