/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:16:13 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:16:16 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src, int count)
{
	char	*tempsrc;
	char	*dest;
	int		i;

	tempsrc = (char *)src;
	i = 0;
	dest = NULL;
	while (tempsrc[i])
		i++;
	if (!(dest = malloc(sizeof(*dest) * (i + 1))))
		return (dest = ft_calloc(1, sizeof(char)));
	i = 0;
	while (tempsrc[i])
	{
		dest[i] = tempsrc[i];
		i++;
	}
	dest[i] = '\0';
	if (count == 1)
		free((char*)src);
	return (dest);
}
