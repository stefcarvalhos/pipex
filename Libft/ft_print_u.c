/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:30:01 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/10 18:25:41 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(unsigned int n)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = (long)n;
	if (nbr > 9)
	{
		count = count + ft_print_u(nbr / 10);
	}
	count = count + ft_print_c((nbr % 10) + '0');
	return (count);
}
