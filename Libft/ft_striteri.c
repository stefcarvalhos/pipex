/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:02:20 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/07 17:54:54 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*static	void	change(unsigned int i, char *c)
{
		if(i >= 4)
		{
			*c = 's';
		}
}
int	main ()
{
	char s[] = "stefanie";
	printf("String original : %s\n", s);
	ft_striteri(s, change);
	printf("String modificada : %s\n", s);
   
}*/