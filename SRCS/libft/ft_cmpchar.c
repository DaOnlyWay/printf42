/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmpchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 18:00:09 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 23:15:18 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
