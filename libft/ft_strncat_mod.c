/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:18:14 by ccroissa          #+#    #+#             */
/*   Updated: 2021/01/25 16:11:01 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat_mod(char src, int nb, int len)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = ft_calloc(nb + len + 1, sizeof(char*))))
		return (NULL);
	while (nb > 0)
	{
		dest[i++] = src;
		nb--;
	}
	return (dest);
}
