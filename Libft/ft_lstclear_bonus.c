/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:22:25 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/12 20:18:45 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*one;

	if (!lst)
		return ;
	while (*lst)
	{
		one = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = one;
	}
	return ;
}
