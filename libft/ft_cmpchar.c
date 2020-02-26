/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:10:56 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:11:01 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmpchar(const char *s1, const char *set, int start, int pos)
{
	int i;

	i = -1;
	if (!(s1) || !(set))
		return (0);
	while (set[++i] && start != -1 && s1[start])
	{
		if (set[i] == s1[start])
		{
			start += pos;
			i = -1;
		}
	}
	return (start);
}
