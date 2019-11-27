/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 01:58:13 by magostin          #+#    #+#             */
/*   Updated: 2019/11/22 19:12:37 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dest;

	size = 0;
	while (s1[size])
		size++;
	if (!(dest = malloc((size + 1) * sizeof(char))))
		return (0);
	size = 0;
	while (s1[size])
	{
		dest[size] = s1[size];
		size++;
	}
	dest[size] = 0;
	return (&dest[0]);
}
