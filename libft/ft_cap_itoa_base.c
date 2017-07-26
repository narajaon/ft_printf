/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cap_itoa_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 09:31:02 by narajaon          #+#    #+#             */
/*   Updated: 2017/07/26 19:21:23 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void		reverse(char *str, int len)
{
	int		start;
	int		end;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		ft_swap(str + start, str + end);
		start++;
		end--;
	}
}

int				ft_cap_ltoa_base(long long int num, char *buff, int base)
{
	int				i;
	long long 		rem;
	int				neg;

	i = 0;
	neg = 0;
	if (num == 0)
	{
		buff[i++] = '0';
		buff[i] = '\0';
		return (1);
	}
	if (num < 0 && base == 10)
	{
		num *= -1;
		neg = 1;
	}
	while (num)
	{
		rem = num % base;
		buff[i++] = (rem > 9) ? (rem - 10 + 'A') : (rem + '0');
		num /= base;
	}
	if (neg)
		buff[i++] = '-';
	buff[i] = '\0';
	reverse(buff, i);
	return (i);
}
