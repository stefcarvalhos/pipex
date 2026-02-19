/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:11:45 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/10 18:25:27 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_print_di(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11), 11);
	if (n < 0)
	{
		count = count + ft_print_c('-');
		n = -n;
	}
	if (n > 9)
	{
		count = count + ft_print_di(n / 10);
	}
	count = count + ft_print_c((n % 10) + '0');
	return (count);
}
