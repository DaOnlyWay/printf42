/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:16:23 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:16:24 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int count)
{
	char	*str;
	int		i;
	int		n;

	n = 0;
	if (!s1 || !s2)
		return (0);
	i = strlen(s1) + strlen(s2);
	if (!(str = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[n])
	{
		str[i] = s2[n];
		n++;
		i++;
	}
	if (count == 1)
		free(s2);
	return (str);
}
