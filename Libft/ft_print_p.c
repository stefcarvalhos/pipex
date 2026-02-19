/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:48:39 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/10 18:25:32 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_p(void *p, char *charset)
{
	int				count;
	unsigned long	end;

	end = (unsigned long)p;
	if (end == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	count = (ft_print_x(end, charset) + 2);
	return (count);
}
