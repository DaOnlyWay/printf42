/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:19:18 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:19:20 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len, int count)
{
	size_t			j;
	char			*dest;

	j = 0;
	dest = 0;
	if (!s)
		return (0);
	if (start > (size_t)ft_strlen(s))
		return (dest = ft_calloc(1, sizeof(char)));
	if (!(dest = malloc((len + 1) * sizeof(*dest))))
		return (NULL);
	while (j < len)
		dest[j++] = s[start++];
	dest[j] = 0;
	if (count == 1)
		free((char *)s);
	return (dest);
}
