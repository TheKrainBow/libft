/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_rmi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:02:19 by magostin          #+#    #+#             */
/*   Updated: 2021/06/25 13:40:40 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strs_rmi(char **strs, int size, int index)
{
	char	**new_strs;
	int		i;
	int		j;

	new_strs = malloc((size) * sizeof(char *));
	if (!(new_strs) || index < 0 || index > size)
		return (NULL);
	i = -1;
	j = 0;
	while (strs[++i])
	{
		if (i == index)
			j++;
		else
			new_strs[i - j] = ft_strdup(strs[i]);
	}
	new_strs[i - j] = NULL;
	return (new_strs);
}
