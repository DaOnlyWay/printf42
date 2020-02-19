/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:20:13 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:20:15 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_string_size(unsigned long n, int base)
{
	int i;

	i = 0;
	if (n <= 0 && base == 10)
		i = 1;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char				*uitoa_base(unsigned long n, char *base)
{
	char	*dest;
	int		base_len;
	int		len;

	dest = NULL;
	base_len = ft_strlen(base);
	len = ft_string_size(n, base_len);
	if (!(dest = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (n == 0)
		dest[0] = '0';
	len--;
	while (n != 0)
	{
		dest[len--] = base[n % base_len];
		n /= base_len;
	}
	return (dest);
}
