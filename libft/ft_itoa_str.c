/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:12:55 by narajaon          #+#    #+#             */
/*   Updated: 2017/07/25 16:47:36 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int		base_len(long n)
{
	if (n < 10)
		return (1);
	return (base_len(n / 10) + 1);
}

static char		*to_asci(char *str, long n)
{
	if (n >= 10)
	{
		to_asci(str, n / 10);
		to_asci(str, n % 10);
	}
	if (n < 10)
	{
		while (*str)
			str++;
		*str = n + '0';
	}
	return (str);
}

int				ft_itoa_str(int n, char *str)
{
	int		val;
	int		ret;

	val = 0;
	ret = (n < 0) ? 1 : 0;
	val = (n < 0) ? -(long)n : (long)n;
	ret += base_len(val);
	if (n < 0)
		*str++ = '-';
	to_asci(str, val);
	return (ret);
}

/*
   int		ft_itoa_str(uintmax_t n, char *s)
   {
   int			i;
   long long	nb;
   long long	sign;
   int			ret;

   sign = n;
   nb = n;
   i = 2 + ((intmax_t)n < 0);
   while (n /= 10)
   i++;
   ret = i;
   s[i--] = '\0';
   s[i--] = nb % 10 + '0';
   while (nb /= 10)
   s[i--] = nb % 10 + '0';
   if (sign < 0)
 *s = '-';
 return (ret);
 }
 */
