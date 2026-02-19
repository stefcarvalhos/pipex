/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:05:01 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 15:17:29 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	total;

	total = 0;
	if (!str)
		return (0);
	while (str[total] != '\0')
		total++;
	return (total);
}
