/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:13:03 by narajaon          #+#    #+#             */
/*   Updated: 2017/08/09 20:04:46 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../ft_printf.h"

#include <unistd.h>

typedef union		u_uni
{
	unsigned int	dec;
	unsigned char	oct[4];
}					t_uni;

#include <stdio.h>
#include <locale.h>

void	ft_putchar_uni(unsigned int uni)
{
	unsigned char	id;
	unsigned char	id_2;
	unsigned char	id_3;
	unsigned char	id_4;
	int				count;
	t_uni			code;

	code.dec = uni;
	id = code.oct[0] >> 7;
	id_2 = code.oct[0] >> 6;
	id_3 = code.oct[0] >> 5;
	id_4 = code.oct[0] >> 4;
	count = 0;
	if (id == 0)
		write(1, &code.oct[0], 1);
	else if (id_4 == 8)
	{
		while (count < 4)
			write(1, &code.oct[count++], 1);
		printf("ici");
	}
	else if (id_3 == 4)
	{
		while (count < 3)
			write(1, &code.oct[count++], 1);
		printf("la");
	}
	else if (id_2 == 2)
	{
		while (count < 2)
			write(1, &code.oct[count++], 1);
		printf("labas");
	}
	printf("\n>>7 = %d\n", id);
	printf(">>6 = %d\n", id_2);
	printf(">>5 = %d\n", id_3);
	printf(">>4 = %d\n", id_4);
}

int		main()
{
	setlocale(LC_ALL, "");
	ft_putchar_uni(L'該');
	//printf("%d\n", 0xF0 >> 3); //30
	//printf("%d\n", 0xE0 >> 4); //14
	//printf("%d\n", 0xC0 >> 5); //6
	return (0);
}
