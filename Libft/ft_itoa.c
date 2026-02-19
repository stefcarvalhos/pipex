/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:37:56 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/06 18:20:11 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len_n(int n);

char	*ft_itoa(int n)
{
	char	*dst;
	int		len;
	long	ln;

	ln = n;
	len = len_n(ln);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (ln < 0)
	{
		dst[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		len--;
		dst[len] = (ln % 10) + '0';
		ln = ln / 10;
	}
	return (dst);
}

static	int	len_n(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
