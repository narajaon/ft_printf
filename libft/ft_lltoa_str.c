/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:33:01 by narajaon          #+#    #+#             */
/*   Updated: 2017/07/25 16:47:35 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		base_len(long long int n)
{
	if (n < 10)
		return (1);
	return (base_len(n / 10) + 1);
}

static char		*to_asci(char *str, long long int n)
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

int				ft_lltoa_str(long long int n, char *str)
{
	int		ret;

	ret = 0;
	ret = (n < 0) ? ret++ : ret;
	ret += base_len(n);
	if (n < 0)
		*str++ = '-';
	n = (n < 0) ? -n : n;
	to_asci(str, n);
	return (ret);
}
