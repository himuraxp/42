/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:02:57 by ylarbi            #+#    #+#             */
/*   Updated: 2015/12/04 15:27:06 by ylarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*trav;

	newlst = f(lst);
	trav = newlst;
	while (lst->next)
	{
		trav->next = f(lst->next);
		trav = trav->next;
		lst = lst->next;
	}
	return (newlst);
}
