/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 09:07:48 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 19:26:21 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (count == 1)
		free (dest);
	if (count == 2)
		free (src);
	return (dest);
}
