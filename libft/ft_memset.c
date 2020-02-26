/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:13:55 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:13:57 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*dest;
	size_t				i;

	i = 0;
	dest = (unsigned char*)b;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
