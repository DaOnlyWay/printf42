/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:20:02 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:20:04 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_string_size(unsigned int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*uitoa(unsigned int n)
{
	char	*dest;
	int		len;

	dest = NULL;
	len = ft_string_size(n);
	if (!(dest = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (n == 0)
		dest[0] = '0';
	else
	{
		dest[len] = 0;
		len--;
		while (n != 0)
		{
			dest[len--] = n % 10 + '0';
			n /= 10;
		}
	}
	return (dest);
}
