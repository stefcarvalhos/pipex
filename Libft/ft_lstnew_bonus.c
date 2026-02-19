/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:37:53 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/12 20:15:01 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*one;

	one = malloc(sizeof(t_list));
	if (!one)
		return (NULL);
	one->content = content;
	one->next = NULL;
	return (one);
}

/*int main()
{
	t_list	*test;
	int	one;	
	one = 42;
	
	test = ft_lstnew(&one);
	printf("%d", *(int *)test->content);
}*/