/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:57:26 by magostin          #+#    #+#             */
/*   Updated: 2021/06/25 13:46:24 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strs_to_tab(int n, ...)
{
	va_list			ap;
	int				i;
	char			**dest;

	va_start(ap, n);
	dest = (char **)malloc(sizeof(char *) * (n + 1));
	if (!(dest))
		return (NULL);
	i = -1;
	while (++i < n)
		dest[i] = ft_strdup(va_arg(ap, char *));
	dest[i] = NULL;
	va_end(ap);
	return (dest);
}
