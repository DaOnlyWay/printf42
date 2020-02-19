/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:17:52 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:17:55 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int				i;
	char			*dest;
	int				len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (len == 0)
		len = 1;
	i = 0;
	if (!(dest = ft_calloc((len + 1), sizeof(char))))
		return (0);
	while (s[i])
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}
