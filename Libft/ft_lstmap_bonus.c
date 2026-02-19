/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:26:38 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/12 21:07:23 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	t_list	*alc;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		alc = f(lst->content);
		if (!alc)
			return (ft_lstclear(&newlist, del), NULL);
		newnode = ft_lstnew(alc);
		if (!newnode)
		{
			del(alc);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
