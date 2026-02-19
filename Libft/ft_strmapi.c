/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:19:50 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/07 17:52:10 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		len;
	int		i;

	len = ft_strlen(s);
	dst = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!dst)
		return (NULL);
	while (*s != '\0')
	{
		dst[i] = f(i, *s);
		i++;
		s++;
	}
	dst[len] = '\0';
	return (dst);
}
/*static	char	change(unsigned int n, char c)
{
		if(n >= 1)
		{
			c = 's';
		}
		return (c);
}
int	main ()
{
	char *s = "stefanie";
	char *result;
	result = ft_strmapi(s, change);
	
	printf("String original : %s\n", s);
    printf("String modificada: %s\n", result);
}*/