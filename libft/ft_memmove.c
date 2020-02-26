/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:13:34 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:14:07 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstalt;
	unsigned char		*srcalt;
	size_t				i;

	if (!dst && !src)
		return (0);
	i = 0;
	dstalt = (unsigned char *)dst;
	srcalt = (unsigned char *)src;
	if (dstalt > srcalt)
	{
		while (len--)
			dstalt[len] = srcalt[len];
		return (dstalt);
	}
	while (i < len)
	{
		dstalt[i] = srcalt[i];
		i++;
	}
	return (dstalt);
}
