/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:12:32 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:12:36 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*src;
	size_t				i;

	i = 0;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return (&src[i]);
		i++;
	}
	return (0);
}
