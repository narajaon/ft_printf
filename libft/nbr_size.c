/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 12:13:57 by narajaon          #+#    #+#             */
/*   Updated: 2017/07/25 15:04:56 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nbr_size(unsigned long long int nbr)
{
	if (nbr < 10)
		return (1);
	return (nbr_size (nbr / 10) + 1);
}
