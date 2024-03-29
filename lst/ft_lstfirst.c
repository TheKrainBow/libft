/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 00:03:12 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/06/25 13:31:12 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfirst(t_list **list)
{
	while (list && *list && (*list)->prev)
		(*list) = (*list)->prev;
}
