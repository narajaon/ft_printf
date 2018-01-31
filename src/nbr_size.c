/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 12:13:57 by narajaon          #+#    #+#             */
/*   Updated: 2018/01/31 15:40:56 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/inc/libft.h"

int		nbr_size(unsigned long long int nbr)
{
	if (nbr < 10)
		return (1);
	return (nbr_size(nbr / 10) + 1);
}
