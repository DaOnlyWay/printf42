/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:15:41 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:15:43 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
		i++;
	while (src[j])
	{
		dest[i++] = src[j];
		j++;
	}
	dest[i] = '\0';
	if (count == 1)
		free(dest);
	if (count == 2)
		free(src);
	if (count == 3)
	{
		free(src);
		free(dest);
	}
	return (dest);
}
