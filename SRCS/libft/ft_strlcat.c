/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:16:31 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:16:43 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dest_len;
	size_t src_len;
	size_t j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (dest_len >= size || size == 0)
		return (src_len + size);
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (dest_len + src_len);
}
