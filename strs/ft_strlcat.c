/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 01:21:50 by magostin          #+#    #+#             */
/*   Updated: 2019/11/27 20:17:08 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		size;

	size = ft_strlen(dst);
	if (size > dstsize)
		return (dstsize + ft_strlen(src));
	return (ft_strlcpy(dst + size, src, dstsize - size) + size);
}
