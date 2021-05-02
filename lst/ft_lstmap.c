/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 00:12:26 by magostin          #+#    #+#             */
/*   Updated: 2021/04/30 23:47:52 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *maillon;
	t_list *maillon_temp;
	t_list *start_new;

	if (!lst)
		return (0);
	if (!(maillon = ft_lstnew(f(lst->content))))
		return (0);
	start_new = maillon;
	lst = lst->next;
	while (lst)
	{
		if (!(maillon_temp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&start_new, del);
			return (0);
		}
		maillon->next = maillon_temp;
		maillon_temp->prev = maillon;
		maillon = maillon_temp;
		lst = lst->next;
	}
	return (start_new);
}
