/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:19:10 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:19:12 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set, int count)
{
	int		end;
	int		start;
	int		len;
	char	*dest;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	start = ft_cmpchar(s1, set, 0, 1);
	end = ft_cmpchar(s1, set, len - 1, -1);
	if (start == len || !(dest = ft_substr(s1, start, end + 1 - start, 0)))
		return (dest = ft_calloc(1, sizeof(*dest)));
	if (count == 1)
		free((char *)s1);
	if (count == 2)
		free((char *)set);
	if (count == 3)
	{
		free((char*)s1);
		free((char*)set);
	}
	return (dest);
}
