/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 04:37:13 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/06/25 13:45:32 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_str(char **a, char **b)
{
	char	*a_t;
	char	*b_t;

	a_t = ft_strdup(*b);
	b_t = ft_strdup(*a);
	free(*a);
	free(*b);
	*a = a_t;
	*b = b_t;
}

char	**ft_sort_strs(char **strs)
{
	char		**copy;
	int			swaped;
	int			i;

	copy = malloc(sizeof(char *) * ft_tablen(strs));
	i = -1;
	while (strs[++i])
		copy[i] = ft_strdup(strs[i]);
	copy[i] = NULL;
	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		i = -1;
		while (copy[++i + 1])
		{
			if (ft_strcmp(copy[i], copy[i + 1]) > 0)
			{
				ft_swap_str(&copy[i], &copy[i + 1]);
				swaped = 1;
			}
		}
	}
	return (copy);
}

void	ft_sort_strs_to(char ***strs)
{
	char	**dest;

	dest = ft_sort_strs(*strs);
	ft_free_tab(*strs);
	*strs = dest;
}
