/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:57:17 by narajaon          #+#    #+#             */
/*   Updated: 2017/04/13 14:15:30 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ret(int nb, int *ret)
{
	int temp;

	temp = 0;
	if (nb == -2147483648)
	{
		nb = nb / 10;
		temp = 8;
	}
	if (nb < 0)
	{
		ft_putchar_ret('-', ret);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_ret(nb / 10, ret);
		ft_putchar_ret(nb % 10 + '0', ret);
	}
	else if (nb <= 9 && nb >= 0)
		ft_putchar_ret(nb % 10 + '0', ret);
	if (temp != 0)
		ft_putchar_ret(temp + '0', ret);
}
