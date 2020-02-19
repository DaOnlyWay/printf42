/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:12:07 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:12:10 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_string_size(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char	*dest;
	int		len;
	int		neg;

	dest = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_string_size(n);
	if (!(dest = ft_calloc(len + 1, sizeof(char))))
		return (dest = ft_calloc(1, sizeof(char)));
	if (n < 0)
	{
		dest[0] = '-';
		n *= -1;
		neg = 0;
	}
	else
		neg = -1;
	len--;
	while (len > neg)
	{
		dest[len--] = n % 10 + '0';
		n /= 10;
	}
	return (dest);
}
