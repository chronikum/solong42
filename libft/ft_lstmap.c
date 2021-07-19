/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:56:24 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/03 14:42:14 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nl);
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstnew(void *content);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*ne;

	if (lst == NULL)
		return (NULL);
	nl = NULL;
	while (lst)
	{
		ne = ft_lstnew((*f)(lst->content));
		if (!ne)
		{
			ft_lstclear(&nl, del);
			return (NULL);
		}
		ft_lstadd_back(&nl, ne);
		ne = ne->next;
		lst = lst->next;
	}
	return (nl);
}
