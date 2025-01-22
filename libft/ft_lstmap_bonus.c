/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:31:29 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 14:33:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*rslt;

	rslt = NULL;
	newlst = ft_calloc(1, sizeof(t_list));
	if (!newlst || !lst)
		return (NULL);
	newlst->content = f(lst->content);
	rslt = newlst;
	while (lst->next)
	{
		newlst->next = ft_calloc(1, sizeof(t_list));
		if (!newlst->next)
			return (ft_lstclear(&rslt, del), NULL);
		lst = lst->next;
		newlst = newlst->next;
		newlst->content = f(lst->content);
	}
	return (rslt);
}
