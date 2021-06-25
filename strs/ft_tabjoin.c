/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:36:20 by magostin          #+#    #+#             */
/*   Updated: 2021/06/25 13:35:37 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabjoin(char **s1, char **s2)
{
	char		**dest;
	int			size;
	int			i;

	size = 0;
	i = -1;
	while (s1 && s1[++i])
		size++;
	i = -1;
	while (s2 && s2[++i])
		size++;
	dest = malloc(sizeof(char *) * (size + 1));
	size = -1;
	i = -1;
	while (s1 && s1[++i])
		dest[++size] = ft_strdup(s1[i]);
	i = -1;
	while (s2 && s2[++i])
		dest[++size] = ft_strdup(s2[i]);
	dest[size + 1] = NULL;
	return (dest);
}
