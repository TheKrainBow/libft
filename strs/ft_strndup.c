/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:29:09 by magostin          #+#    #+#             */
/*   Updated: 2021/06/25 13:38:33 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int start, int len)
{
	int		i;
	char	*dest;

	if (!str || start > (int)ft_strlen(str) || len < 0)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_min(len, (int)ft_strlen(str)) + 1));
	if (!(dest))
		return (NULL);
	i = -1;
	while (i < len && str[++i + start])
		dest[i] = str[i + start];
	dest[i] = 0;
	return (dest);
}
